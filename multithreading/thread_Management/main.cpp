#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
std::mutex mu_;

void shared_print(std::string message, int id)
{
    std::lock_guard<std::mutex> l(mu_);
    std::cout<<message << "  " <<id <<std::endl;
}

void function()
{
    for (int i =0;i>-100;i--)
    {
        std::lock_guard<std::mutex> l(mu_);
        std::cout<<"From t1: "<<i <<std::endl;
    }
}

int main()
{
    std::thread t1(function);
    for (int i =0; i<100;i++)
    {
        shared_print("From Main", i);
    }
    t1.join();
}