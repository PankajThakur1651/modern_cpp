project(exerice_lsp)
set(CMAKE_CXX_STANDARD 17)

add_executable(exerice_lsp main.cpp)

target_compile_options(exerice_lsp PRIVATE -Werror -Wall -Wextra)