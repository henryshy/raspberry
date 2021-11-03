cmake_minimum_required (VERSION 2.6)

project (mqtt)

include_directories (paho_mqtt)

aux_source_directory (paho_mqtt SRC_LIST)

add_executable(mqtt mqtt.c ${SRC_LIST})