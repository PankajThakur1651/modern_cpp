#include <iostream>
#include <vector>
#include <memory>
#include <functional>

int trigger_the_callback(std::function<int(int)> const &func) {
    int value = 12;
    return func(value);
}

int lambda_with_capture_list(int &x) {
    auto lambda = [&x](int value) mutable {
        x++;
        return x + value;

    };
    return trigger_the_callback(lambda);
}


int main() {
    int x = 10;
    std::cout << lambda_with_capture_list(x) <<std::endl;
    std::cout << lambda_with_capture_list(x) <<std::endl;
    std::cout << lambda_with_capture_list(x) <<std::endl;
}


