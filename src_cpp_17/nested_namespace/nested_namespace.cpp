#include <iostream>
#include <tuple>
#include <set>
#include <cassert>

using namespace std;
namespace cpp_11 {
    namespace cpp_14 {
        namespace first {
            namespace second {
                void before_cpp_17() {
                    std::cerr << "cpp 11 and cpp14" << std::endl;
                }
            }
        }
    }
}

namespace cpp_17::first::second {
    void after_cpp_17() {
        std::cerr << "After cpp 17" << std::endl;
    }
}

int main() {
    cpp_11::cpp_14::first::second::before_cpp_17();
    cpp_17::first::second::after_cpp_17();
}