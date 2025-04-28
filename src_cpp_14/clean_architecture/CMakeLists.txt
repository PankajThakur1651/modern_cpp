project(clean_architecture)
add_executable(clean_architecture main.cpp)
target_compile_options(clean_architecture PRIVATE -Werror -Wall -Wextra -fno-exceptions -fno-rtti)