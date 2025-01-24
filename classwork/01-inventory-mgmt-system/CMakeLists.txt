cmake_minimum_required(VERSION 3.30)
project(01_inventory_mgmt_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(01_inventory_mgmt_system main.cpp
        Product.h
        Inventory.h
        InventoryMGMTSystem.h)
