project(dip)

set(CMAKE_CXX_STANDARD 17)

add_executable(dip dip.cpp)

target_compile_options(dip PRIVATE -Werror -Wall -Wextra)
