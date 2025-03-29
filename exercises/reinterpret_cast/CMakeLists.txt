project(casting)
set(CMAKE_CXX_STANDARD 17)
add_executable(casting casting.cpp)
target_compile_options(casting PRIVATE -Werror -Wall -Wextra)