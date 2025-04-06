project(self_assignment_in_copy_constructor)
add_executable(${PROJECT_NAME} main.cpp
        ../operator_overloading/Test.cpp
        ../operator_overloading/Test.h)
target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -ggdb -O2)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
