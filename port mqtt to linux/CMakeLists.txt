cmake_minimum_required (VERSION 2.6)

project (mqtt)

include_directories (mqttlib)

aux_source_directory (mqttlib SRC_LIST)

add_executable(mqtt mqtt.c ${SRC_LIST})