#include <iostream>
#include <string_view>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::string_view sv = str;

    str[0] = 'X'; 

    std::cout << "String: " << str << '\n';
    std::cout << "String View: " << sv << '\n'; // sv sees the modified string
}
