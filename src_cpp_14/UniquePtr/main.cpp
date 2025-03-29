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

    void show()
    {
        std::cout<<"I am in show \n";
    }
};

int main()
{
    std::unique_ptr<Test> test = std::make_unique<Test>();
    std::unique_ptr<Test[]> test_2 (new Test[3]);
    test_2[0].show();
}
