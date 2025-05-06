#include <condition_variable>
#include <deque>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
std::deque<int> g_queue;
std::mutex g_mu;
condition_variable g_cv;

void producer() {
  int count = 10;
  while (count >= 0) {
    std::unique_lock<std::mutex> lk(g_mu);
    g_queue.push_front(count);
    lk.unlock();
    g_cv.notify_one();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    count--;
  }
}

void consumer() {
  int data = -1;
  while (data != 0) {
    std::unique_lock<std::mutex> lk(g_mu);
    g_cv.wait(lk, []() { return !g_queue.empty(); });
    data = g_queue.back();
    std::cout << "data is: " << data << std::endl;
    g_queue.pop_back();
    lk.unlock();
  }
}

int main() {
  std::thread t1(producer);
  std::thread t2(consumer);
  t1.join();
  t2.join();
}