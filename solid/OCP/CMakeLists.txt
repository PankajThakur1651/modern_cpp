project(ocp)

add_executable(ocp ocp.cpp)

target_compile_options(ocp PRIVATE -Werror -Wall -Wextra)
