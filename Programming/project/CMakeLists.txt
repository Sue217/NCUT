cmake_minimum_required(VERSION 3.20)
project(project)

set(CMAKE_CXX_STANDARD 11)

add_executable(project main.cpp)
include_directories("./list.h")
