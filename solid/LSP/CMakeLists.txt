project(lsp)

add_executable(lsp lsp.cpp
        racing_car_lsp.cpp
        racing_car_lsp.h)

target_compile_options(lsp PRIVATE -Werror -Wall -Wextra)
