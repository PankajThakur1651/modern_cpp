project(cpp_features)
set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_features main.cpp)

target_compile_options(cpp_features PRIVATE -Werror -Wall -Wextra)

