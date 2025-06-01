#include <iostream>
#include <ranges>
#include <vector>


template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
T add(T a, T b) {
    return a + b;
}


template<typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "Sum is: " << add(11, 12);

    std::cout<<"With float value is: " <<add(11.0, 12.0) <<std::endl;
}