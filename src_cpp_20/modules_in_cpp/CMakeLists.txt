cmake_minimum_required(VERSION 3.20)
project(MyModularApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable modules in GCC
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-fmodules-ts)
endif()

# One executable with both files
add_executable(main_exec
        hello_world.cpp
        main.cpp
)

target_compile_features(main_exec PRIVATE cxx_std_20)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(main_exec PRIVATE -fmodules-ts)
endif()
