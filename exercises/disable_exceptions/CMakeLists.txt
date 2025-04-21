project(disable_exceptions)
add_executable(disable_exceptions main.cpp)
target_compile_options(disable_exceptions PRIVATE -Werror -Wall -Wextra -fno-exceptions -fno-rtti)