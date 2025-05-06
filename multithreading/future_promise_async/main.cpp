#include <future>
#include <iostream>
#include <memory>
#include <vector>

int factorial(int num) {
  int result = 1;
  for (int i = num; i > 1; i--) {
    result *= i;
  }
  return result;
}

int factorial_2(std::future<int> &fu) {
  int result = 1;
  int num = fu.get(); // Parent thread sets this value from outside
  for (int i = num; i > 1; i--) {
    result *= i;
  }
  return result;
}

std::future<int> get_value() {
  std::promise<int> p;
  std::future<int> f = p.get_future();
  p.set_value(11);
  return f;
}

std::future<int> async_task() {
  std::promise<int> p;
  std::future<int> f = p.get_future();

  try {
    throw std::runtime_error("Something bad happened!");
  } catch (...) {
    p.set_exception(std::current_exception());
  }

  return f;
}

void engage_future_and_promise() {
  std::promise<int> promise_;
  std::future<int> fut_ = promise_.get_future();
  promise_.set_value(11);
  std::cout << "value set by promise is: " << fut_.get() << std::endl;
}

int main() {

  // Engage promise and future basic
  engage_future_and_promise();

  // get value of child thread into parent thread
  std::future<int> fu = std::async(factorial, 5);
  std::cout << "Value is: " << fu.get() << std::endl;

  // set value into child
  std::promise<int> pro;
  std::future<int> f = pro.get_future();
  auto value = std::async(std::launch::async, factorial_2, std::ref(f));
  pro.set_value(6);
  std::cout << "Factorial is: " << value.get() << std::endl;

  // method returning promise
  auto obj = get_value();
  std::cout << "Value is: " << obj.get() << std::endl;

  // Exception in c++
  std::future<int> result = async_task();
  try {
    int val = result.get(); // This will throw
    std::cout << "Value: " << val << std::endl;
  } catch (const std::exception &ex) {
    std::cout << "Caught exception: " << ex.what() << std::endl;
  }
}
