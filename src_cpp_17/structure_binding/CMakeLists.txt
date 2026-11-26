project(std)

add_executable(structure_binding structure_binding.cpp)

if(BUILD_TESTING)
    add_test(NAME structure_binding_smoke COMMAND structure_binding)
endif()


target_compile_options(structure_binding PRIVATE -Werror -Wall -Wextra)
install(TARGETS structure_binding DESTINATION ${CMAKE_INSTALL_PREFIX})
