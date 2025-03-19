project(about_array)
add_executable(about_array main.cpp)
target_compile_options(about_array PRIVATE -Werror -Wall -Wextra)
install(TARGETS about_array DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
