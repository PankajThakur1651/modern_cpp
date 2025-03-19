project(crtp)
add_executable(crtp main.cpp)
target_compile_options(crtp PRIVATE -Werror -Wall -Wextra)
install(TARGETS crtp DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
