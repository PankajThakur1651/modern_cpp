project(min_element)

add_executable(min_element min_element.cpp)

target_compile_options(min_element PRIVATE -Werror -Wall -Wextra)

install(TARGETS min_element DESTINATION ${CMAKE_INSTALL_PREFIX})