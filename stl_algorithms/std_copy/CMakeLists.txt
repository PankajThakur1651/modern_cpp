project(std_copy)

add_executable(std_copy main.cpp)

target_compile_options(std_copy PRIVATE -Werror -Wall -Wextra)

install(TARGETS std_copy DESTINATION ${CMAKE_INSTALL_PREFIX})