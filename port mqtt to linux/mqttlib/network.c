
#include "mqtt.h"
#include "network.h"

#if USE_SOCKET

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
        n->network_err_fn=err;
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
           exit(0);
       }
    }
}

err_t network_concect(network* n, const ip_addr_t *ipaddr, u16_t port, network_connected_fn connected){
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
            exit(0);
        }
        n->network_connected_fn=connected;
    }
    else{
        printf("no network, bind fail\n");
        exit(0);
    }
}

int linux_write(network* n, unsigned char* buffer, int len, int timeout_ms){
    struct timeval tv;

    tv.tv_sec = 0;  /* 30 Secs Timeout */
    tv.tv_usec = timeout_ms * 1000;  // Not init'ing this can cause strange errors

    setsockopt(n->sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv,sizeof(struct timeval));
    int	rc = write(n->sockfd, buffer, len);
    return rc;
}
int linux_read(network * n, unsigned char* buffer, int len, int timeout_ms)
{
    struct timeval interval = {timeout_ms / 1000, (timeout_ms % 1000) * 1000};
    if (interval.tv_sec < 0 || (interval.tv_sec == 0 && interval.tv_usec <= 0))
    {
        interval.tv_sec = 0;
        interval.tv_usec = 100;
    }

    setsockopt(n->sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&interval, sizeof(struct timeval));

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
