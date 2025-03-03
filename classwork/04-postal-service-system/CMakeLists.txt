cmake_minimum_required(VERSION 3.30)
project(04_postal_service_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(04_postal_service_system main.cpp
        Package.h
        OneDayPackage.h
        TwoDayPackage.h
        Employee.h
        PostalSystem.h)
