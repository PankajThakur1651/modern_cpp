#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <vector>

class Car {
public:
    int year{2024};

    Car &operator++() {
        year++;
        return *this;
    }

    Car &operator++(int) {
        Car *temp = this;
        year++;
        return *temp;
    }


};


int main() {

}
