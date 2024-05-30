project(composition)

add_executable(composition Singleton.cpp Main.cpp)

target_compile_options(composition PRIVATE -Werror -Wall -Wextra)