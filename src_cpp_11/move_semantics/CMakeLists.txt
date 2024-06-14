project(cpp_features)

add_executable(move_semantics move_semantics.cpp)

target_compile_options(move_semantics PRIVATE -Werror -Wall -Wextra)
