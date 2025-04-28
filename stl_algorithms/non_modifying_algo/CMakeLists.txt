project(non_modifying_algo)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_options(${PROJECT_NAME}  PRIVATE -Werror -Wall -Wextra)

install(TARGETS ${PROJECT_NAME}  DESTINATION ${CMAKE_INSTALL_PREFIX})