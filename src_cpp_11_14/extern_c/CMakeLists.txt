cmake_minimum_required(VERSION 3.28)

project(extern_c)

set(CMAKE_CXX_STANDARD 17)

add_library(func_lib
        one_c_file.h
        one_c_file.c
)

add_executable(extern_c main.cpp)

target_link_libraries(extern_c
        PRIVATE
        func_lib)


