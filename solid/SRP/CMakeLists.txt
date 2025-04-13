project(srp)
add_executable(srp srp.cpp
        student.cpp
        student.h
        student_db.cpp
        student_db.h)

target_compile_options(srp PRIVATE -Werror -Wall -Wextra)
