# cmake_minimum_required(VERSION <specify CMake version here>)
project(HTower)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ht_main.cpp
        HTower.cpp
        HTower.h)

add_executable(HTower ${SOURCE_FILES})