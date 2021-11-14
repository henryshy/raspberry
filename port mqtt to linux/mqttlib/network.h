

#ifndef MQTT_NETWORK_H
#define MQTT_NETWORK_H

#ifdef __cplusplus
extern "C" {
#endif


#include "mqtt.h"

#if USE_SOCKET
#include <errno.h>
#include "port_types.h"
#include <sys/time.h>
#include "mqtt_opts.h"
#define altcp_arg network_arg
#define altcp_bind network_bind
#define altcp_connect network_connect
#define altcp_err network_err
#define altcp_recv reg_recv_fn
#define altcp_poll reg_poll_fn
#define altcp_sent reg_sent_fn
#define altcp_close network_close
#define sys_timeout network_init_timeout
#define sys_untimeout network_del_timeout
#define pbuf_free free


typedef void  (*network_tcp_err_fn)(void *arg, err_t err);
typedef err_t (*network_tcp_connected_fn)(void *arg, struct altcp_pcb *conn, err_t err);
typedef err_t (*network_tcp_recv_fn)(void *arg, struct altcp_pcb *conn, struct pbuf *p, err_t err);
typedef err_t (*network_tcp_sent_fn)(void *arg, struct altcp_pcb *conn, u16_t len);
typedef err_t (*network_tcp_poll_fn)(void *arg, struct altcp_pcb *conn);
typedef err_t (*network_read_fn) (struct altcp_pcb*,unsigned char*,int);
typedef err_t (*network_write_fn) (struct altcp_pcb*, unsigned char*, int);
typedef void (*network_timeout_handler)(void *arg);

 struct altcp_pcb{
    void* arg;
    int sockfd;
    u8_t pollinterval;
    ip_addr_t *ipaddr;
    u16_t port;
    struct itimerval *timer;
    network_tcp_connected_fn connected_fn;
    network_tcp_err_fn err_fn;
    network_tcp_recv_fn recv_fn;
    network_tcp_poll_fn poll_fn;
    network_tcp_sent_fn sent_fn;
    network_read_fn  read_fn;
    network_write_fn write_fn;
};
typedef struct Timer
{
    struct timeval end_time;
} Timer;
struct pbuf{
    char payload[MQTT_VAR_HEADER_BUFFER_LEN];
    u16_t tot_len;
};



void network_init(struct altcp_pcb *tpcb);
int network_write(struct altcp_pcb *tpcb, u8_t* buffer, int len);
int network_read(struct altcp_pcb *tpcb, struct pbuf* buf, int len);
void network_arg(struct altcp_pcb *tpcb,void* arg);
err_t network_connect(struct altcp_pcb *tpcb, const ip_addr_t *ipaddr, u16_t port, network_tcp_connected_fn connected);
err_t network_bind(struct altcp_pcb *tpcb, const ip_addr_t *ipaddr, u16_t port);
void network_err(struct altcp_pcb *tpcb ,network_tcp_err_fn err);
void reg_recv_fn(struct altcp_pcb *tpcb,network_tcp_recv_fn recv);
void reg_sent_fn(struct altcp_pcb *tpcb,network_tcp_sent_fn sent);
void reg_poll_fn(struct altcp_pcb *tpcb,network_tcp_poll_fn poll,u8_t interval);
err_t network_close(struct altcp_pcb *tpcb);
void network_init_timeout(u32_t msecs,network_timeout_handler handler, mqtt_client_t *client);
void network_del_timeout(network_timeout_handler handler,mqtt_client_t *client);
u8_t pbuf_get_at(struct pbuf *p,u16_t index);
void pbuf_copy_partial(const struct pbuf *buf, void *dataptr, u16_t len, u16_t offset);

int MQTTYield(mqtt_client_t* client);

#endif //if use socket
#ifdef __cplusplus
}
#endif

#endif //MQTT_NETWORK_H
