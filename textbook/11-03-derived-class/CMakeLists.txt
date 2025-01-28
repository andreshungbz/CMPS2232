cmake_minimum_required(VERSION 3.30)
project(11_03_derived_class)

set(CMAKE_CXX_STANDARD 20)

add_executable(11_03_derived_class main.cpp
        CommissionEmployee.cpp
        CommissionEmployee.h
        BasePlusCommissionEmployee.cpp
        BasePlusCommissionEmployee.h)
