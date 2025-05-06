project(dependent)

add_executable(dependent main.cpp)


message("CMAKE_SOURCE_DIR is ${CMAKE_SOURCE_DIR}")


target_include_directories(
        dependent
        PRIVATE
        ${CMAKE_SOURCE_DIR}/cpp_linkings/dependent_and_service/service

)
target_link_libraries(
        dependent
        PUBLIC
        first
)
target_compile_options(dependent PRIVATE -Werror -Wall -Wextra)