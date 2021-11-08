

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
typedef struct Timer
{
    struct timeval end_time;
} Timer;
typedef  struct network{
        int sockfd;
        int (*mqttread) (struct network*,unsigned char*,int,int);
        int (*mqttwrite) (struct Network*, unsigned char*, int, int);
    }network;
#define altcp_pcb network

int linux_read(network *, unsigned char*, int, int);
int linux_write(network *, unsigned char*, int, int);
DLLExport void NetworkInit(network*);
DLLExport int NetworkConnect(network*, char*, int);
DLLExport void NetworkDisconnect(network*);


#endif


#endif //MQTT_NETWORK_H
