#include <iostream>
#include "Test.h"

int main() {
    Test t;
    auto  x = t[3];

    std::cout<<"x: "<<x <<std::endl;
    return 0;
}
