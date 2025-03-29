#include <iostream>
#include <vector>
#include <memory>

class Dog {
public:

    std::weak_ptr<Dog> friend_;
    std::string name_;

    ~Dog() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Dog(std::string str)
    {
        name_ = str;
        std::cout<<__PRETTY_FUNCTION__  <<std::endl;
    }

    void make_friend(std::shared_ptr<Dog> f)
    {
        friend_ = f;
        std::cout<<"Name is " <<friend_.lock()->name_ <<std::endl;
    }
};


int main() {

    auto first_dog = std::make_shared<Dog>("Rockey");

    auto second_dog = std::make_shared<Dog>("Taunshi");

    first_dog->make_friend(second_dog);

    second_dog->make_friend(first_dog);
}


