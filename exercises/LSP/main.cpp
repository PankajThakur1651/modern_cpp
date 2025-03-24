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
        throw std::runtime_error("Racing_car Some Exception");
    }

    double get_cockpit_width() {
        std::cout << "Racing car get_cockpit_width " << std::endl;
        return 12;
    }

};

int main() {

    auto first_car = std::make_shared<Car>();
    auto second_car = std::make_shared<Car>();

    auto racing_car = std::make_shared<Racing_car>();
    std::list<std::shared_ptr<Car> > cars_{std::move(first_car), std::move(second_car), std::move(racing_car)};

    for (auto &car: cars_) {
        car->get_cabin_width();
    }


}
