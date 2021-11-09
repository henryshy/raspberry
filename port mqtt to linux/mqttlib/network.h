

#ifndef MQTT_NETWORK_H
#define MQTT_NETWORK_H

#if USE_SOCKET
#include "mqtt.h"
#include <sys/time.h>
#include <errno.h>
#if defined(WIN32_DLL) || defined(WIN64_DLL)
#define DLLImport __declspec(dllimport)
  #define DLLExport __declspec(dllexport)
#elif defined(LINUX_SO)
#define DLLImport extern
  #define DLLExport  __attribute__ ((visibility ("default")))
#else
#define DLLImport
#define DLLExport
#endif
typedef void  (*network_err_fn)(void *arg, err_t err);
typedef err_t (*network_connected_fn)(void *arg, struct altcp_pcb *conn, err_t err);

typedef struct Timer
{
    struct timeval end_time;
} Timer;
typedef  struct network{
    void* arg;
    int sockfd;
    ip_addr_t *ipaddr;
    u16_t port;
    err_t (*netwrok_close_fn)(struct altcp_pcb *conn);
    err_t (*network_bind_fn)(struct altcp_pcb *conn, const ip_addr_t *ipaddr, u16_t port);
    err_t (*network_accept_fn)(void *arg, struct altcp_pcb *new_conn, err_t err);
    err_t (*network_connected_fn)(void *arg, struct altcp_pcb *conn, err_t err);
    err_t (*network_poll_fn)(void *arg, struct altcp_pcb *conn);
     void  (*network_err_fn)(void *arg, err_t err);
    err_t (*mqttread_fn) (struct network*,unsigned char*,int,int);
    err_t (*mqttwrite_fn) (struct Network*, unsigned char*, int, int);
}network;

#define altcp_pcb network

int linux_read(network *, unsigned char*, int, int);
int linux_write(network *, unsigned char*, int, int);


#endif


#endif //MQTT_NETWORK_H
