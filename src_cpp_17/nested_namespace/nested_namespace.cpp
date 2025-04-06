#include <iostream>

using namespace std;
namespace cpp_11 {
    namespace cpp_14 {
        namespace first {
            namespace second {
                void using_cpp_14() { std::cout << "cpp 11 and cpp14" << std::endl; }
            } // namespace second
        } // namespace first
    } // namespace cpp_14
} // namespace cpp_11

namespace cpp_17 {
    namespace first {
        namespace second {
            void after_cpp_17() { std::cout << "After cpp 17" << std::endl; }
        } // namespace cpp_17::first::second
    }
}

int main() {
    cpp_11::cpp_14::first::second::using_cpp_14();
    cpp_17::first::second::after_cpp_17();
}
