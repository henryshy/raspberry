#include "mqtt.h"
#if USE_SOCKET
#include "network.h"


void reg_recv_fn(struct altcp_pcb *tpcb,network_recv_fn recv){
    if(tpcb){
        tpcb->recv_fn=recv;
    }
}
void reg_sent_fn(struct altcp_pcb *tpcb,network_sent_fn sent){
    if(tpcb){
        tpcb->sent_fn=sent;
    }
}
void reg_poll_fn(struct altcp_pcb *tpcb,network_poll_fn poll,u8_t interval){
    if(tpcb){
        tpcb->poll_fn=poll;
        tpcb->pollinterval=interval;
        if(tpcb->poll_fn){
            tpcb->poll_fn(tpcb,interval);
        }
    }
}
err_t network_close(network* n){
    if(n&&n->netwrok_close_fn){
        return n->netwrok_close_fn(n);
    }
    return ERR_VAL;
}
void network_arg(network* n,void* arg){
    if(n){
        n->arg=arg;
    }
}
void network_err(network* n ,network_err_fn err){
    if(n){
        n->err_fn=err;
    }
}
err_t network_bind(network* n, const ip_addr_t *ipaddr, u16_t port){
    if(n){
        struct sockaddr_in client_addr;
        int client_addr_length;
        memset(&client_addr,0,sizeof(struct sockaddr_in));
        client_addr.sin_family=AF_INET;
        client_addr.sin_port= htons(port);
        client_addr.sin_addr.s_addr= htons((uint16_t) &ipaddr);
        client_addr_length=sizeof(client_addr);
       if(bind(n->sockfd,&client_addr,client_addr_length)==-1){
           printf("client bind fail!\n");
           close(n->sockfd);
           return ERR_ABRT;
           exit(0);
       }
       return ERR_OK;
    }
    else {
        printf("no network, bind fail\n");
        return ERR_ARG;
        exit(0);
    }
}

err_t network_connect(network* n, const ip_addr_t *ipaddr, u16_t port, network_connected_fn connected){
    if(n) {

        struct sockaddr_in server_addr;
        memset(&server_addr,0,sizeof(struct sockaddr_in));


        server_addr.sin_family=AF_INET;
        server_addr.sin_port= htons(port);
        server_addr.sin_addr.s_addr= htons((uint16_t) &ipaddr);
        socklen_t server_addr_length=sizeof(server_addr);

        if(connect(n->sockfd,(struct sockaddr*)&server_addr,server_addr_length)<0){
            printf("can not connect to server!\n");
            close(n->sockfd);
            return ERR_ABRT;
            exit(0);
        }
        n->connected_fn=connected;
        return ERR_OK;
    }
    else{
        printf("no network, bind fail\n");
        return ERR_ARG;
        exit(0);
    }
}

int network_write(network* n, unsigned char* buffer, int len){

    int	rc = write(n->sockfd, buffer, len);
    return rc;
}
int network_read(network * n, unsigned char* buffer, int len, int timeout_ms)
{

    int bytes = 0;
    while (bytes < len)
    {
        int rc = recv(n->sockfd, &buffer[bytes], (size_t)(len - bytes), 0);
        if (rc == -1)
        {
            if (errno != EAGAIN && errno != EWOULDBLOCK)
                bytes = -1;
            break;
        }
        else if (rc == 0)
        {
            bytes = 0;
            break;
        }
        else
            bytes += rc;
    }
    return bytes;
}




#endif
