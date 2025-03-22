#include <iostream>
#include <vector>
#include <memory>
#include <thread>

class Functor {
public:
    void operator()(std::string &str) {
        str = "Changed in functor \n";
        std::cout << " Thread id is " << std::this_thread::get_id() << std::endl;
    }
};

int main() {

    Functor fnktr;
    std::string str = "OS is interface between hardware and user";
    // Using RAII
    // Wrapper t1
    std::thread t1(fnktr, std::ref(str));

    t1.join();
    std::cout << "String change to " << str << std::endl;

    // thread can only be moved
    std::cout << "Main Thread id is " << std::this_thread::get_id() << std::endl;
    std::cout << "Number of threads in parallel " << std::thread::hardware_concurrency() << std::endl;
}
