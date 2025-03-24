#include <iostream>
#include <vector>
#include <memory>
#include <future>
#include <functional>
#include <deque>

int factorial(int num) {
    int result = 1;
    for (int i = num; i > 1; i--) {
        result *= i;
    }
    return result;
}

int main() {

    std::vector<std::packaged_task<int()>> task_q;

    // Task 1: bound with 5
    std::packaged_task<int()> pt_1(std::bind(factorial, 5));
    task_q.push_back(std::move(pt_1));

    // Task 2: bound with 11
    std::packaged_task<int()> pt_2(std::bind(factorial, 11));
    task_q.push_back(std::move(pt_2));

    for (auto& task : task_q) {
        std::future<int> fut = task.get_future();
        task();
        std::cout << "Result: " << fut.get() << std::endl;
    }
}
