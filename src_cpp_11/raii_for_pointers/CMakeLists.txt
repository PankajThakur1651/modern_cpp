project(cpp_features)
set(CMAKE_CXX_STANDARD 17)

add_executable(raii_for_pointers main.cpp Entity.cpp Entity.h)

target_compile_options(raii_for_pointers PRIVATE -Werror -Wall -Wextra)
