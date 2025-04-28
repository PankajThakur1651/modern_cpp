project(casting)
add_executable(casting casting.cpp)
target_compile_options(casting PRIVATE -Werror -Wall -Wextra)