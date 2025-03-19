#include <iostream>
#include <vector>
#include <memory>

class Dog {
public:
    ~Dog() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

class Yellow_Dog : public Dog {
public:
    ~Yellow_Dog() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};


std::shared_ptr<Dog> create_object() {
    return std::make_shared<Yellow_Dog>();
}

Dog *create_object_using_new() {
    return new Yellow_Dog();
}

int main() {
    [[maybe_unused]]auto obj = create_object();
    // obj destruction will call both classes destructor

    [[maybe_unused]] auto obj_2 = create_object_using_new();
    // obj destruction will call only base class destructor. explicitly declare base destructor as vtual
    delete obj_2; //
}


