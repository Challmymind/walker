cmake_minimum_required(VERSION 3.19.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

project(walker)

add_executable(walker main.cpp)

target_include_directories(walker PRIVATE "inc")
