cmake_minimum_required(VERSION 3.19)
project(module3_task1)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC src/*.cpp)
add_library(graph STATIC ${SRC})
target_include_directories(graph PUBLIC include/)

add_executable(module3_task1 main.cpp)
target_link_libraries(module3_task1 graph)
