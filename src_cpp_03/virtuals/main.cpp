#include <iostream>

class Car {
public:
  virtual void display_function() {}

  void show_functions() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  virtual ~Car() = default;

  int engine_{};
  int ecu_cost_{};
};

class Audi : public virtual Car {
public:
  void display_function() override {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  void show_functions() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class BMW : public virtual Car {
public:
  void display_function() override {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  void show_functions() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Hybrid : public virtual BMW, public virtual Audi {
public:
  void display_function() override {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
};

int main() {
  Hybrid hybrid_car;
  std::cout << "Size of Hybrid: " << sizeof(hybrid_car) << " bytes"
            << std::endl;
  //    hybrid_car.display_function();
}