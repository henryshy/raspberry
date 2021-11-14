
#include "mqtt.h"
#include "mqtt_client.h"


int main(){
    example_do_connect(&static_client,MQTT_SERVER_IP);
    network_init(static_client.conn);
    while (1){
        MQTTYield(&static_client);
    }
    return 0;
}