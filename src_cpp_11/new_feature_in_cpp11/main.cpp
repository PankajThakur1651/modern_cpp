#include <iostream>
#include <vector>
#include <memory>
#include <initializer_list>

using namespace std;


// Uniform Initialization Search Order
// Regular constructor that takes the appropriate parameters
// Aggregate Initializer

namespace uniform_initialization_search_order {
    class Dog {
    public:
        int age;

        Dog(int a) : age(a) {
            std::cout << "Default constructor " << std::endl;
        }

        Dog(initializer_list<int> const &vec) {
            std::cout << "Initializer list " << std::endl;
            age = *vec.begin();
        }

        int get_age() {
            return age;
        }
    };
}
namespace auto_in_cpp11 {
    std::vector<int> vec_of_ints{1, 2, 3, 4};

    void before_cpp_11() {

        std::vector<int>::iterator itr = vec_of_ints.begin(); // cpp03
        itr++;
        std::cout << "*itr ===>" << *itr << std::endl;
    }

    void after_cpp_11() {
        auto itr = vec_of_ints.cbegin();
        std::cout << "*itr" << *itr << std::endl;


        for (auto rev_itr = vec_of_ints.rbegin(); rev_itr != vec_of_ints.rend(); rev_itr++) {
            std::cout << " " << *rev_itr << ", ";
        }

        std::cout << std::endl;

    }
}

namespace nullptr_in_cpp11 {
    void foo(int /*i*/) {
        std::cout << "foo(int)" << std::endl;
    }

    void foo(char * /*c*/) {
        std::cout << "foo(char*)" << std::endl;
    }


}

namespace enum_classes {
    enum class apple {
        RED, GREEN, BLUE
    };

    enum class orange {
        BIG, SMALL
    };

    void compare() {
        apple a{apple::BLUE};
        orange o{orange::BIG};

        if (static_cast<int>(a) != static_cast<int>(o)) {
            std::cout << "Both apples are not Equal \n";
        }
    }
}

namespace constexper_in_cpp_11 {
    constexpr int func() { return 10; }

    void declare_array_from_constexpr_func() {
        int array[func() + 2] = {};

        std::cout << "size of array is " << sizeof(array) / sizeof(array[0]) << std::endl;
    }

}

namespace lambda_function_in_cpp {
    template<typename func>
    void filter(func f, vector<int> &v) {
        for (auto const &value: v) {
            if (f(value)) {
                std::cout << "Value is: " << value << std::endl;
            }
        }
    }

}

int main() {
    uniform_initialization_search_order::Dog d{3};
    std::cout << d.get_age() << std::endl;
    auto_in_cpp11::before_cpp_11();
    auto_in_cpp11::after_cpp_11();

    nullptr_in_cpp11::foo(nullptr);
    enum_classes::compare();

    //static assert
    static_assert(sizeof(int) == 4, "Size of int should be 4");

    //default and delete keywords
    constexper_in_cpp_11::declare_array_from_constexpr_func();
    // String literals

    std::vector<int> vec_of_ints{1, 2, 3, 4, 5};
    lambda_function_in_cpp::filter([](int x) {
        return x % 2 == 0;
    }, vec_of_ints);
}