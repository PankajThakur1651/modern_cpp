project(views)

add_executable(views
        main.cpp
)

target_compile_options(views PRIVATE -Werror -Wall -Wextra)
install(TARGETS views DESTINATION ${CMAKE_INSTALL_PREFIX})
