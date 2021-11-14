#ifndef LWIP_HDR_APPS_MQTT_CLIENT_H
#define LWIP_HDR_APPS_MQTT_CLIENT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef struct mqtt_client_s mqtt_client_t;
#define USE_SOCKET 1
#define USE_LWIP 0



#if USE_SOCKET
#include "network.h"
#include "port_types.h"

#define TCP_WRITE_FLAG_COPY 0x01
#define TCP_WRITE_FLAG_MORE 0x02
#endif




typedef enum
{
    /** Accepted */
    MQTT_CONNECT_ACCEPTED                 = 0,
    /** Refused protocol version */
    MQTT_CONNECT_REFUSED_PROTOCOL_VERSION = 1,
    /** Refused identifier */
    MQTT_CONNECT_REFUSED_IDENTIFIER       = 2,
    /** Refused server */
    MQTT_CONNECT_REFUSED_SERVER           = 3,
    /** Refused user credentials */
    MQTT_CONNECT_REFUSED_USERNAME_PASS    = 4,
    /** Refused not authorized */
    MQTT_CONNECT_REFUSED_NOT_AUTHORIZED_  = 5,
    /** Disconnected */
    MQTT_CONNECT_DISCONNECTED             = 256,
    /** Timeout */
    MQTT_CONNECT_TIMEOUT                  = 257
} mqtt_connection_status_t;

typedef void (*mqtt_incoming_data_cb_t)(void *arg, const u8_t *data, u16_t len, u8_t flags);
typedef void (*mqtt_incoming_publish_cb_t)(void *arg, const char *topic, u32_t tot_len);
typedef void (*mqtt_request_cb_t)(void *arg, err_t err);
typedef void (*mqtt_connection_cb_t)(mqtt_client_t *client, void *arg, mqtt_connection_status_t status);




#if USE_SOCKET

#define LWIP_ARRAYSIZE(x) (sizeof(x)/sizeof((x)[0]))

#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <netinet/tcp.h>
#include <sys/param.h>
#include <netdb.h>
#include "mqtt_client.h"

#endif


#include <stdlib.h>
#include "mqtt_opts.h"
#include "mqtt_priv.h"


#define mqtt_subscribe(client, topic, qos, cb, arg) mqtt_sub_unsub(client, topic, qos, cb, arg, 1)
#define mqtt_unsubscribe(client, topic, cb, arg) mqtt_sub_unsub(client, topic, 0, cb, arg, 0)

/**
 * @ingroup mqtt
 * Client information and connection parameters */
struct mqtt_connect_client_info_t {
  /** Client identifier, must be set by caller */
  const char *client_id;
  /** User name, set to NULL if not used */
  const char* client_user;
  /** Password, set to NULL if not used */
  const char* client_pass;
  /** keep alive time in seconds, 0 to disable keep alive functionality*/
  u16_t  keep_alive;
  /** will topic, set to NULL if will is not to be used,
      will_msg, will_qos and will retain are then ignored */
  const char* will_topic;
  /** will_msg, see will_topic */
  const char* will_msg;
  /** will_qos, see will_topic */
  u8_t will_qos;
  /** will_retain, see will_topic */
  u8_t will_retain;
};

/**
 * @ingroup mqtt
 * Data callback flags */
enum {
  /** Flag set when last fragment of data arrives in data callback */
  MQTT_DATA_FLAG_LAST = 1
};


err_t mqtt_client_connect(mqtt_client_t *client, const ip_addr_t *ipaddr, u16_t port, mqtt_connection_cb_t cb, void *arg,const struct mqtt_connect_client_info_t *client_info);

void mqtt_disconnect(mqtt_client_t *client);

mqtt_client_t *mqtt_client_new(void);
void mqtt_client_free(mqtt_client_t* client);

u8_t mqtt_client_is_connected(mqtt_client_t *client);

void mqtt_set_inpub_callback(mqtt_client_t *client, mqtt_incoming_publish_cb_t,
                             mqtt_incoming_data_cb_t data_cb, void *arg);

err_t mqtt_sub_unsub(mqtt_client_t *client, const char *topic, u8_t qos, mqtt_request_cb_t cb, void *arg, u8_t sub);

err_t mqtt_publish(mqtt_client_t *client, const char *topic, const void *payload, u16_t payload_length, u8_t qos, u8_t retain,mqtt_request_cb_t cb, void *arg);

err_t mqtt_publish(mqtt_client_t *client, const char *topic, const void *payload, u16_t payload_length, u8_t qos, u8_t retain,
                                    mqtt_request_cb_t cb, void *arg);


#ifdef __cplusplus
}
#endif


#endif