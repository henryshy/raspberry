

#ifndef MQTT_NETWORK_H
#define MQTT_NETWORK_H

#if USE_SOCKET
#include "mqtt.h"
#include <errno.h>


#define altcp_pcb network
#define altcp_arg network_arg
#define altcp_bind network_bind
#define altcp_connect(a,b,c,d) network_connect(a,b,c,d)
#define altcp_err(a,b) network_err(a,b)
#define altcp_recv reg_recv_fn
#define altcp_poll reg_poll_fn
#define altcp_sent reg_sent_fn
#define altcp_close network_close
#define sys_timeout network_init_timeout
#define sys_untimeout network_del_timeout
typedef void  (*network_err_fn)(void *arg, err_t err);
typedef err_t (*network_connected_fn)(void *arg, struct altcp_pcb *conn, err_t err);
typedef err_t (*network_recv_fn)(void *arg, struct altcp_pcb *conn, struct pbuf *p, err_t err);
typedef err_t (*network_sent_fn)(void *arg, struct altcp_pcb *conn, u16_t len);
typedef err_t (*network_poll_fn)(void *arg, struct altcp_pcb *conn);
typedef err_t (*network_read_fn) (struct network*,unsigned char*,int,int);
typedef err_t (*network_write_fn) (struct network*, unsigned char*, int, int);
typedef void (*network_timeout_handler)(void *arg);

struct pbuf{
    char* payload;
};

typedef  struct network{
    void* arg;
    int sockfd;
    u8_t pollinterval;
    ip_addr_t *ipaddr;
    u16_t port;
    struct itimerval *timer;
    network_connected_fn connected_fn;
    network_err_fn err_fn;
    network_recv_fn recv_fn;
    network_poll_fn poll_fn;
    network_sent_fn sent_fn;
    network_read_fn  read_fn;
    network_write_fn write_fn;
}network;


int linux_read(network *, unsigned char*, int, int);
int linux_write(network *, unsigned char*, int, int);
void network_arg(network* n,void* arg);
err_t network_connect(network* n, const ip_addr_t *ipaddr, u16_t port, network_connected_fn connected);
err_t network_bind(network* n, const ip_addr_t *ipaddr, u16_t port);
void network_err(network* n ,network_err_fn err);
void reg_recv_fn(struct altcp_pcb *tpcb,network_recv_fn recv);
void reg_sent_fn(struct altcp_pcb *tpcb,network_sent_fn sent);
void reg_poll_fn(struct altcp_pcb *tpcb,network_poll_fn poll,u8_t interval);
err_t network_close(network* n);
void network_init_timeout(u32_t msecs,network_timeout_handler handler, mqtt_client_t *client);
void network_del_timeout(network_timeout_handler handler,mqtt_client_t *client){

#endif //if use socket


#endif //MQTT_NETWORK_H
