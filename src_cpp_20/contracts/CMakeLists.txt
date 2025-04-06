project(contracts)
add_executable(contracts main.cpp)
target_compile_options(contracts PRIVATE -Werror -Wall -Wextra)
install(TARGETS contracts DESTINATION ${CMAKE_INSTALL_PREFIX})
