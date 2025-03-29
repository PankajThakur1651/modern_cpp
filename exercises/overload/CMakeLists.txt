project(overload)
set(CMAKE_CXX_STANDARD 11)
add_executable(overload main.cpp)
target_compile_options(overload PRIVATE -Werror -Wall -Wextra)