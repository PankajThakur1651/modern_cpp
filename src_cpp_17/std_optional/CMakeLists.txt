project(std_optional)

add_executable(std_optional std_optional.cpp)

target_compile_options(std_optional PRIVATE -Werror -Wall -Wextra)

install(TARGETS std_optional DESTINATION ${CMAKE_INSTALL_PREFIX})