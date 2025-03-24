#include <iostream>
#include <memory>
class Test{
public:
    Test() {
        std::cout<<"Test constructor \n";
    }

    ~Test() {
        std::cout<<"Test Destructor \n";
    }
};

int main()
{
    std::unique_ptr<Test> test = std::make_unique<Test>();

}
