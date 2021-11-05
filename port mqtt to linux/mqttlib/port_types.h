
#ifndef MQTT_PORT_TYPES_H
#define MQTT_PORT_TYPES_H

#include "mqtt.h"

typedef unsigned char u8_t;
typedef unsigned short  u16_t;
typedef unsigned int u32_t;
typedef signed char err_t;

typedef enum {
/** No error, everything OK. */
    ERR_OK         = 0,
/** Out of memory error.     */
    ERR_MEM        = -1,
/** Buffer error.            */
    ERR_BUF        = -2,
/** Timeout.                 */
    ERR_TIMEOUT    = -3,
/** Routing problem.         */
    ERR_RTE        = -4,
/** Operation in progress    */
    ERR_INPROGRESS = -5,
/** Illegal value.           */
    ERR_VAL        = -6,
/** Operation would block.   */
    ERR_WOULDBLOCK = -7,
/** Address in use.          */
    ERR_USE        = -8,
/** Already connecting.      */
    ERR_ALREADY    = -9,
/** Conn already established.*/
    ERR_ISCONN     = -10,
/** Not connected.           */
    ERR_CONN       = -11,
/** Low-level netif error    */
    ERR_IF         = -12,
/** Connection aborted.      */
    ERR_ABRT       = -13,
/** Connection reset.        */
    ERR_RST        = -14,
/** Connection closed.       */
    ERR_CLSD       = -15,
/** Illegal argument.        */
    ERR_ARG        = -16
} err_enum_t;

typedef struct ip_addr_t{
    u32_t addr;
}ip_addr_t;

#include <sys/types.h>



#endif //MQTT_PORT_TYPES_H
