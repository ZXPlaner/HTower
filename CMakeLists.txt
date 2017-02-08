# cmake_minimum_required(VERSION <specify CMake version here>)
project(HTower)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        README.md)

add_executable(HTower ${SOURCE_FILES})