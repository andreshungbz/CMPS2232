cmake_minimum_required(VERSION 3.30)
project(09_15_static_class_members)

set(CMAKE_CXX_STANDARD 20)

add_executable(09_15_static_class_members main.cpp
        Employee.cpp
        Employee.h)
