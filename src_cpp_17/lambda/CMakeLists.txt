project(lambda)

add_executable(lambda main.cpp)

target_compile_options(lambda PRIVATE -Werror -Wall -Wextra)

install(TARGETS lambda DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
