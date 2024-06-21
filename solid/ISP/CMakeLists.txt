project(isp)

set(CMAKE_CXX_STANDARD 17)

add_executable(isp isp.cpp
        print.h
        scan.h
        fax.h
        xerox_work_center.cpp
        xerox_work_center.h
        printer_scanner.cpp
        printer_scanner.h
        conan_printer.cpp
        conan_printer.h
        print.h
)

target_compile_options(isp PRIVATE -Werror -Wall -Wextra)
