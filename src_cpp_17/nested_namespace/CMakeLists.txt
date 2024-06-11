project(nested_namespace)

set(CMAKE_CXX_STANDARD 11)
add_executable(nested_namespace nested_namespace.cpp)

target_compile_options(nested_namespace PRIVATE -Werror -Wall -Wextra)

install(TARGETS nested_namespace DESTINATION ${CMAKE_INSTALL_PREFIX})