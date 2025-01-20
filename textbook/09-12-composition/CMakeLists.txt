cmake_minimum_required(VERSION 3.30)
project(09_12_composition)

set(CMAKE_CXX_STANDARD 20)

add_executable(09_12_composition main.cpp
        Date.cpp
        Date.h
        Employee.cpp
        Employee.h)
