#include <iostream>
#include <string>
#include <list>
#include <memory>

class Vector
{
public:
    Vector(int sz): size_{sz}, elem_{new double [size_]}
    {

    }
private:
    int size_;
    double * elem_;
};
int main() {

}
