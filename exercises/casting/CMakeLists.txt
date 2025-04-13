project(dcast)

add_executable(dcast main.cpp)

target_compile_options(dcast PRIVATE -Werror -Wall -Wextra)