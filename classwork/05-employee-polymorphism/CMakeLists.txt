cmake_minimum_required(VERSION 3.30)
project(05_employee_polymorphism)

set(CMAKE_CXX_STANDARD 20)

add_executable(05_employee_polymorphism main.cpp
        Employee.cpp
        Employee.h
        Manager.cpp
        Manager.h
        Intern.cpp
        Intern.h
        Contractor.cpp
        Contractor.h)
