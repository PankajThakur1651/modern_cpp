#include <iostream>
#include <thread>
#include <future>
std::once_flag g_flag;
class A {
public:
    void f(int x, char c) {
        std::cout << "x: " << x << std::endl;
        std::cout << "c: " << c << std::endl;
        int i =10;
        while(i >=0)
        {
            i--;
            std::cout<<"this will run " << i <<" times" <<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    long g(double x) {
        std::cout << "x: " << x << std::endl;
        return 0;
    }

    int operator()(int N) { std::cout << "N: " << N << std::endl; return 0; }

};

int main() {
    A a;
    std::thread t1(a, 7); //copy_of_a() in a different thread
    std::thread t2(std::ref(a), 6); // a() in different thread
    std::thread t3(A(), 6); // Temp A
    std::thread([](int a )
                {
                    std::cout<<"a is: "<<a<<std::endl;
                }, 6).detach();

    std::thread t4(&A::f,a, 8, 'w'); // copy of_a

    t2.join();
    t3.join();
    t1.join();
    t4.join();
    //std::bind(), std::async(), std::call_once();
}