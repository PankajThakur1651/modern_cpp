project(template_argument_deduction)

add_executable(template_argument_deduction
        template_argument_deduction.cpp
        template_argument_deduction.h
        main.cpp
)

target_compile_options(template_argument_deduction PRIVATE -Werror -Wall -Wextra)

install(TARGETS template_argument_deduction DESTINATION ${CMAKE_INSTALL_PREFIX})
