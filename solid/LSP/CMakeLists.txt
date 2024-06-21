project(lsp)

set(CMAKE_CXX_STANDARD 17)

add_executable(lsp lsp.cpp)

target_compile_options(lsp PRIVATE -Werror -Wall -Wextra)
