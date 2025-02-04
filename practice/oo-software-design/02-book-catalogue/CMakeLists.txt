cmake_minimum_required(VERSION 3.30)
project(02_book_catalogue)

set(CMAKE_CXX_STANDARD 20)

add_executable(02_book_catalogue main.cpp
        Book.cpp
        Book.h
        Catalogue.cpp
        Catalogue.h)
