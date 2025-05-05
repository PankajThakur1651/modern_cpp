project(first)

add_library(first service_in_lib.h service_in_lib.cpp)

target_compile_options(first PRIVATE -Werror -Wall -Wextra)