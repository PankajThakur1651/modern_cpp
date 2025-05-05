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


int add(int a , int b)
{
    return a+b;
}

class Test
{
public:
    Test() = default;
    void greet(int x)
    {
        x_+=x;

        std::cout<<"Greet is called \n";
    }
    int x_;
};
void std_bind_usage(){
    auto sum = std::bind (add, 10, std::placeholders::_1);
    std::cout<< sum(12) <<std::endl;

    Test t;
    auto value = std::bind (&Test::greet, &t, 1);
    value();



}
int main() {
    int x = 10;
    std::cout << lambda_with_capture_list(x) <<std::endl;
    std::cout << lambda_with_capture_list(x) <<std::endl;
    std::cout << lambda_with_capture_list(x) <<std::endl;
    std_bind_usage();

}


