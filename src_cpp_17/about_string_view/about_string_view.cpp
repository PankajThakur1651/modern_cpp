#include <iostream>
#include <string_view>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::string_view sv = str;

    str[0] = 'X';
    std::cout << "String: " << str << '\n';
    std::cout << "String View: " << sv << '\n'; // sv sees the modified string

    sv = "Thakur";

    std::cout<<"string view str is "<<sv <<std::endl;

    std::cout << "String: " << str << '\n';
    std::cout << "String View: " << sv << '\n'; // sv sees the modified string

}
