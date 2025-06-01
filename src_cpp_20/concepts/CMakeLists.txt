project(concept)
add_executable(concept main.cpp)
target_compile_options(concept PRIVATE -Werror -Wall -Wextra)
install(TARGETS concept DESTINATION ${CMAKE_INSTALL_PREFIX})
