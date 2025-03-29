project(exercise)
set(CMAKE_CXX_STANDARD 17)
add_executable(exercise main.cpp)
target_compile_options(exercise PRIVATE -Werror -Wall -Wextra)