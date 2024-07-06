cmake_minimum_required(VERSION 3.8)
project(cpp_example)

file(GLOB_RECURSE SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.cpp)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)

add_subdirectory(third_part)

if(BUILD_EXECUTE)
  add_executable(${PROJECT_NAME} ${SRC_LIST})
  target_include_directories(${PROJECT_NAME}
                             PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/install/include)
  target_link_directories(${PROJECT_NAME} PUBLIC
                          ${CMAKE_CURRENT_SOURCE_DIR}/install/lib)
  target_link_libraries(${PROJECT_NAME} PRIVATE spdlog jsoncpp)
endif(BUILD_EXECUTE)
