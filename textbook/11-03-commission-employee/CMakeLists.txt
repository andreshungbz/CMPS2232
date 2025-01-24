cmake_minimum_required(VERSION 3.30)
project(11_03_commission_employee)

set(CMAKE_CXX_STANDARD 20)

add_executable(11_03_commission_employee main.cpp
        CommissionEmployee.cpp
        CommissionEmployee.h)
