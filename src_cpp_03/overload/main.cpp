#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>

class Car {
public:
  int year{2024};

  Car &operator++() {
    std::cout << "Prefix ";
    year++;
    return *this;
  }

  Car &operator++(int) {
    std::cout << "Postfix ";
    Car *temp = this;
    year++;
    return *temp;
  }
};

int main() {

  Car c;
  std::cout << " ----->" << (c++).year << std::endl;
  std::cout << " ----->" << (++c).year << std::endl;
}
