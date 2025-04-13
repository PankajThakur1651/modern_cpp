project(do_not_push)
set(CMAKE_CXX_STANDARD 17)
add_executable(do_not_push main.cpp)
target_compile_options(do_not_push PRIVATE -Werror -Wall -Wextra)