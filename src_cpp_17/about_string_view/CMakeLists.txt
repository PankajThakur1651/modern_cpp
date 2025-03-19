project(about_string_view)

add_executable( about_string_view about_string_view.cpp)

target_compile_options( about_string_view PRIVATE -Werror -Wall -Wextra)

install(TARGETS about_string_view DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

