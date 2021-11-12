cmake_minimum_required (VERSION 2.6)

project (mqtt)

include_directories (mqttlib)

aux_source_directory (mqttlib SRC_LIST)

add_executable(mqtt mqtt_client.c ${SRC_LIST} )