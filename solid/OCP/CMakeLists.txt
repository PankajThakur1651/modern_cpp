project(ocp)

set(CMAKE_CXX_STANDARD 17)

add_executable(ocp ocp.cpp)

target_compile_options(ocp PRIVATE -Werror -Wall -Wextra)
