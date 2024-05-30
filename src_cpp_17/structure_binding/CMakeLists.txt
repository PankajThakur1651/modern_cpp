project(structure_binding)

add_executable(structure_binding structure_binding.cpp)

target_compile_options(structure_binding PRIVATE -Werror -Wall -Wextra)

install(TARGETS structure_binding DESTINATION ${CMAKE_INSTALL_PREFIX})