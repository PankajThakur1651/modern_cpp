#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
#include <fstream>

class LogFile {
  std::mutex mu_;
  std::mutex mu2_;
  std::ofstream file_;

public:
  LogFile() { file_.open("logs.txt"); }

  void shared_print(std::string id, int value) {
    std::lock(mu_, mu2_);
    std::lock_guard<std::mutex> lck(mu_, std::adopt_lock);
    std::lock_guard<std::mutex> lck2(mu2_, std::adopt_lock);
    std::cout << "From " << id << " value " << value << std::endl;
  }

  void shared_print_2(std::string id, int value) {
    std::lock(mu_, mu2_);
    std::lock_guard<std::mutex> lck(mu_, std::adopt_lock);
    std::lock_guard<std::mutex> lck2(mu2_, std::adopt_lock);
    std::cout << "From " << id << " value " << value << std::endl;
  }
};

void function1(LogFile &log) {
  for (int i = 0; i >= -100; i--) {
    log.shared_print("function1", i);
  }
}
/*
 * 1. Prefer locking single Mutex
 * Avoid locking a mutex and then calling a user defined function
 * use std::lock() to more than one mutexes, it has
 * Lock the mutex in the same order
 *
 * Locking Granularity: protects small amount of data
 * Coarse grained lock: protects big amount of data
 *
 *
 */
int main() {

  LogFile log;
  std::thread t1(function1, std::ref(log));
  for (int i = 0; i < 100; i++) {
    log.shared_print_2("Main", i);
  }
  t1.join();
}