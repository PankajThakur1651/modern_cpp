project(dynamic_pointer_casting)

add_executable(dynamic_pointer_casting move_semantics.cpp)

target_compile_options(dynamic_pointer_casting PRIVATE  -Wall -Wextra)
