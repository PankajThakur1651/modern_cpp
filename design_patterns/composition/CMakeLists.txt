project(composition)

add_executable(composition Singleton.cpp main.cpp)

target_compile_options(composition PRIVATE -Werror -Wall -Wextra)
