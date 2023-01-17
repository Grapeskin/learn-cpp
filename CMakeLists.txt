cmake_minimum_required(VERSION 3.8)
project(cpp_example)

file(GLOB_RECURSE SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC
    third_part/spdlog/include
    third_part/jsoncpp/include
)
target_link_directories(${PROJECT_NAME} PUBLIC
    third_part/spdlog/lib
    third_part/jsoncpp/lib
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    jsoncpp
    spdlog
)

set(MQTT_MAIN mqtt_main)
add_executable(${MQTT_MAIN} ${PROJECT_SOURCE_DIR}/src/mqtt_main.cpp)

target_include_directories(${MQTT_MAIN} PUBLIC
    third_part/paho.mqtt.c/include
    third_part/paho.mqtt.cpp/include
)
target_link_directories(${MQTT_MAIN} PUBLIC
    third_part/paho.mqtt.c/lib
    third_part/paho.mqtt.cpp/lib
)
target_link_libraries(${MQTT_MAIN}
    paho-mqtt3a
    paho-mqtt3c
    paho-mqttpp3
)