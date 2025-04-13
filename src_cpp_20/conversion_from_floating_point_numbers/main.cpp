#include <iostream>
#include <string>
#include <sstream>
#include <format>
using namespace std;

int main()
{
    float pi = 3.14f;

    std::string str = ( std::stringstream { } <<pi).str();

    std::cout<<"Str is: "<<str <<std::endl;

    std::cout<<"Using to_string " <<to_string(pi) <<std::endl;


    std::cout<<"using formats " <<std::format("{}", pi);
}