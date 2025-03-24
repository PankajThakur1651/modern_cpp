project(dcast)
set(CMAKE_CXX_STANDARD 17)

add_executable(dcast main.cpp)

target_compile_options(dcast PRIVATE -Werror -Wall -Wextra)