cmake_minimum_required(VERSION 3.30)
project(12_07_payroll_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(12_07_payroll_system main.cpp
        Employee.cpp
        Employee.h
        SalariedEmployee.cpp
        SalariedEmployee.h
        CommissionEmployee.cpp
        CommissionEmployee.h
        BasePlusCommissionEmployee.cpp
        BasePlusCommissionEmployee.h)
