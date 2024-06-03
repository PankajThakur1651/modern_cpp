project(variable_declaration_in_if)

add_executable(variable_declaration_in_if
        main.cpp
)

target_compile_options(variable_declaration_in_if PRIVATE -Werror -Wall -Wextra)

install(TARGETS variable_declaration_in_if DESTINATION ${CMAKE_INSTALL_PREFIX})