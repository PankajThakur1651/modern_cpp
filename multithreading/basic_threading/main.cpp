#include <iostream>
#include <memory>
#include <thread>
#include <vector>

void function_1() {
  for (int i = 0; i < 10; i++) {
    std::cout << "Thread prints " << i << std::endl;
  }
}

int main() {
  std::thread t1(function_1);
  t1.join();
}
