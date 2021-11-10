

#ifndef MQTT_NETWORK_H
#define MQTT_NETWORK_H

#if USE_SOCKET
#include "mqtt.h"
#include <sys/time.h>
#include <errno.h>

#define altcp_pcb network
#define altcp_arg network_arg
#define altcp_bind network_bind
#define altcp_connect(a,b,c,d) network_connect(a,b,c,d)
#define altcp_err network_err
#define altcp_recv reg_recv_fn
#define altcp_poll reg_poll_fn
#define altcp_sent reg_sent_fn
typedef void  (*network_err_fn)(void *arg, err_t err);
typedef err_t (*network_connected_fn)(void *arg, struct altcp_pcb *conn, err_t err);
typedef err_t (*network_recv_fn)(void *arg, struct altcp_pcb *conn, struct pbuf *p, err_t err);
typedef err_t (*network_sent_fn)(void *arg, struct altcp_pcb *conn, u16_t len);
typedef err_t (*network_poll_fn)(void *arg, struct altcp_pcb *conn);

typedef struct Timer
{
    struct timeval end_time;
} Timer;
typedef  struct network{
    void* arg;
    int sockfd;
    u8_t pollinterval;
    ip_addr_t *ipaddr;
    u16_t port;
    err_t (*netwrok_close_fn)(struct altcp_pcb *conn);
    network_connected_fn connected_fn;
    network_err_fn err_fn;
    network_recv_fn recv_fn;
    network_poll_fn poll_fn;
    network_sent_fn sent_fn;
    err_t (*mqttread_fn) (struct network*,unsigned char*,int,int);
    err_t (*mqttwrite_fn) (struct network*, unsigned char*, int, int);
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
#endif


#endif //MQTT_NETWORK_H
