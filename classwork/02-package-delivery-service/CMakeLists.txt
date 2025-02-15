cmake_minimum_required(VERSION 3.30)
project(02_package_delivery_service)

set(CMAKE_CXX_STANDARD 20)

add_executable(02_package_delivery_service main.cpp
        Package.cpp
        Package.h
        TwoDayPackage.cpp
        TwoDayPackage.h
        OvernightPackage.cpp
        OvernightPackage.h)
