project(isp)

set(CMAKE_CXX_STANDARD 17)

add_executable(isp isp.cpp)

target_compile_options(isp PRIVATE -Werror -Wall -Wextra)
