#include <iostream>
#include <compare>

using namespace std;
struct Entity {

    int i;
    int j;
    float f;

    constexpr auto operator<=>(Entity const &) const = default;
};

// Designated Initializers
Entity designated_initializers() {
    Entity s{.i =2, .j=42, .f=31.4f};
    return s;
}

struct Entity_2 {

    int i;
    int j;
    float f;

    constexpr auto operator<=>(Entity_2 const &) const = default;
};

//5 concepts /auto concept
auto add(std::integral auto lhs, std::integral auto rhs) {

    return lhs + rhs;
}

int main() {
    // 1. designated Initializer
    auto first_initializer = designated_initializers();

    // 2. 3-way comparison

    Entity_2 first = Entity_2{1, 2, 3};
    Entity_2 second = Entity_2{2, 3, 4};

    auto result = first <=> second;

    std::cout << "Is first entity less than second: " << std::boolalpha << (result < 0) << "\n";
    std::cout << "Is first entity equal to second: " << std::boolalpha << (result == 0) << "\n";
    std::cout << "Is first entity greater than second: " << std::boolalpha << (result > 0) << "\n";


    //3  Modules Help to modularize the code
    //4 coroutines no std;ib support

    //5 concepts/auto concept
    std::cout<< "Sum is: "<< add(11,12);

    //6 <format>
}

