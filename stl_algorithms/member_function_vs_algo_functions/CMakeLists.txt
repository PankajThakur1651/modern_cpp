project(member_function_vs_algo_functions)

add_executable(member_function_vs_algo_functions main.cpp)

target_compile_options(member_function_vs_algo_functions PRIVATE -Werror -Wall -Wextra)

install(TARGETS member_function_vs_algo_functions DESTINATION ${CMAKE_INSTALL_PREFIX})