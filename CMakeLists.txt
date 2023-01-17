cmake_minimum_required(VERSION 3.8)
project(cpp_example)

file(GLOB_RECURSE SRC_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC
    third_part/spdlog/include
    third_part/jsoncpp/include
)
target_link_directories(${PROJECT_NAME} PUBLIC
    third_part/spdlog/lib
    third_part/jsoncpp/lib
)

target_link_libraries(${PROJECT_NAME} PUBLIC jsoncpp spdlog)
