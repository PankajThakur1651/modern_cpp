#include <iostream>
#include <memory>

class Base {
public:
    Base() = default;

    virtual ~Base() = default; // Needed for dynamic_cast
};

class Derived : public Base {
public:
    void hello() { std::cout << "Hello from Derived!\n"; }
};

int main() {
    std::shared_ptr<Base> base = std::make_shared<Derived>();

    std::shared_ptr<Derived> derived = std::dynamic_pointer_cast<Derived>(base);
    if (derived) {
        derived->hello(); // Safe to use
    } else {
        std::cout << "Cast failed.\n";
    }

    // custom deleter
    std::shared_ptr<Base> ptr = std::shared_ptr<Base>(new Base(), [](Base *b) {
        std::cout << "Custom deleter \n";
        delete b;

    });


    //std::shared_ptr<Base> arr(new Base[10], [](Base* p){ delete[] p; });

    return 0;
}
