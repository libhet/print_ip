cmake_minimum_required(VERSION 3.2)
project(print_ip)

set(CMAKE_CXX_STANDARD 14)

add_executable(print_ip src/main.cpp src/print_ip.h src/is_stl_container.h)