project(dip)
add_executable(dip dip.cpp)

target_compile_options(dip PRIVATE -Werror -Wall -Wextra)
