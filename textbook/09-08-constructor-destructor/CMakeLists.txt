cmake_minimum_required(VERSION 3.30)
project(09_08_constructor_destructor)

set(CMAKE_CXX_STANDARD 20)

add_executable(09_08_constructor_destructor main.cpp
        CreateAndDestroy.cpp
        CreateAndDestroy.h)
