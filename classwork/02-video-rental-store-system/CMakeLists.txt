cmake_minimum_required(VERSION 3.30)
project(02_video_rental_store_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(02_video_rental_store_system main.cpp
        Customer.h
        RentalItem.h
        Transaction.h
        RentalSystem.h
        Clerk.h
        Manager.h
)
