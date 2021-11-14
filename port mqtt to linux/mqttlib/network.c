#include "mqtt.h"
#if USE_SOCKET
#include "network.h"
#include "sys/time.h"

void network_init(struct altcp_pcb *tpcb){
    tpcb->write_fn=network_write;
    tpcb->read_fn=network_read;
}
void reg_recv_fn(struct altcp_pcb *tpcb,network_tcp_recv_fn recv){
    if(tpcb){
        tpcb->recv_fn=recv;
    }
}
void reg_sent_fn(struct altcp_pcb *tpcb,network_tcp_sent_fn sent){
    if(tpcb){
        tpcb->sent_fn=sent;
    }
}
void reg_poll_fn(struct altcp_pcb *tpcb,network_tcp_poll_fn poll,u8_t interval){
    if(tpcb){
        tpcb->poll_fn=poll;
        tpcb->pollinterval=interval;
    }
}

err_t network_close(struct altcp_pcb *tpcb){
    if(tpcb){
        if((close(tpcb->sockfd))==0) {
            return ERR_OK;
        }
        else
            return ERR_CLSD;
    }
    return ERR_VAL;
}
void network_arg(struct altcp_pcb *tpcb,void* arg){
    if(tpcb){
        tpcb->arg=arg;
    }
}
void network_err(struct altcp_pcb *tpcb ,network_tcp_err_fn errf){
    if(tpcb){
        tpcb->err_fn=errf;
    }
}
err_t network_bind(struct altcp_pcb *tpcb, const ip_addr_t *ipaddr, u16_t port){
//    if(tpcb){
//        struct sockaddr_in client_addr;
//        int client_addr_length;
//        memset(&client_addr,0,sizeof(struct sockaddr_in));
//        client_addr.sin_family=AF_INET;
//        client_addr.sin_port= htons(port);
//        client_addr.sin_addr.s_addr= htons((uint16_t) &ipaddr);
//        client_addr_length=sizeof(client_addr);
//       if(bind(tpcb->sockfd,(struct sockaddr*)&client_addr,client_addr_length)==-1){
//           printf("client bind fail!\n");
//           close(tpcb->sockfd);
//           return ERR_ABRT;
//       }
//       return ERR_OK;
//    }
//    else {
//        printf("no network, bind fail\n");
//        return ERR_ARG;
//        exit(0);
//    }
}

err_t network_connect(struct altcp_pcb *tpcb, const ip_addr_t *ipaddr, u16_t port, network_tcp_connected_fn connected){
    if(tpcb) {

        struct sockaddr_in server_addr;
        memset(&server_addr,0,sizeof(struct sockaddr_in));


        server_addr.sin_family=AF_INET;
        server_addr.sin_port= htons(1883);
        server_addr.sin_addr.s_addr= inet_addr("192.168.10.160");
        socklen_t server_addr_length=sizeof(server_addr);

        if(connect(tpcb->sockfd,(struct sockaddr*)&server_addr,server_addr_length)<0){
            printf("can not connect to server!\n");
            close(tpcb->sockfd);
            return ERR_ABRT;
        }
        tpcb->connected_fn=connected;
        return ERR_OK;
    }
    else{
        printf("no network, bind fail\n");
        return ERR_ARG;
    }
}

int network_write(struct altcp_pcb *tpcb, u8_t* buffer, int len){

    int	rc = write(tpcb->sockfd, buffer, len);
    if(rc){
        tpcb->sent_fn(tpcb->arg,tpcb,len);
    }
    return rc;
}
int network_read(struct altcp_pcb *tpcb, struct pbuf* buf, int len)
{

    int rc=recv(tpcb->sockfd,buf->payload,len,MSG_DONTWAIT);
    if(rc) {
        tpcb->recv_fn(tpcb->arg, tpcb, buf, ERR_OK);
    }
    else{
        tpcb->recv_fn(tpcb->arg, tpcb, buf, ERR_BUF);
    }

    return rc;
}

void network_init_timeout(u32_t msecs,network_timeout_handler handler, mqtt_client_t *client){
    signal(SIGALRM,handler);
    client->conn->timer->it_interval.tv_sec=0;
    client->conn->timer->it_interval.tv_usec=0;

    client->conn->timer->it_value.tv_sec=msecs/1000;
    client->conn->timer->it_value.tv_usec=0;

    setitimer(ITIMER_REAL,client->conn->timer,NULL);
}
void network_del_timeout(network_timeout_handler handler,mqtt_client_t *client){
    client->conn->timer->it_interval.tv_usec=0;
    client->conn->timer->it_interval.tv_sec=0;
    client->conn->timer->it_value.tv_usec=0;
    client->conn->timer->it_value.tv_sec=0;
    setitimer(ITIMER_REAL,client->conn->timer,NULL);
}
u8_t pbuf_get_at(struct pbuf *p,u16_t index){
    return p->payload[index];
}
void pbuf_copy_partial(const struct pbuf *buf, void *dataptr, u16_t len, u16_t offset){
    memcpy(&((char *)dataptr)[0],&((char*)buf->payload)[offset],len);
}

int MQTTYield(mqtt_client_t* client){
    int rc=1;
    struct pbuf* buf= calloc(1,sizeof (struct pbuf));
    rc=client->conn->read_fn(client->conn->sockfd,buf->payload,MQTT_VAR_HEADER_BUFFER_LEN);
    return rc;
}
#endif
