#include <iostream>
#include <string>
#include <list>
#include <memory>

class Car {
public:
    virtual double get_cabin_width() {
        std::cout << "Car get_cabin_width " << std::endl;
        return 11;
    }

    virtual ~Car() {

    }
};

class Racing_car : public Car {
public:
    double get_cabin_width() {
        std::cout << "Racing car " << std::endl;
        return 12;
    }

};

class Non_racing_car : public Car {
public:
    double get_cabin_width() {
        std::cout << "Racing car " << std::endl;
        return 12;
    }

};

int main() {

    std::shared_ptr<Car> car = std::make_shared<Racing_car>();
    [[maybe_unused]] auto object = dynamic_cast<Non_racing_car *>(car.get());
    if (object) // Invalid conversion
    {
        std::cout << "This should not get printed \n";
    }
}
