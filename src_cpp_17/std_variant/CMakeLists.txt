project(std_variant)

add_executable(std_variant std_variant.cpp)

target_compile_options(std_variant PRIVATE -Werror -Wall -Wextra)

install(TARGETS std_variant DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
