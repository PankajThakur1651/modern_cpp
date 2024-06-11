#include "Entity.h"
#include <iostream>
#include <memory>
#include <vector>

void foo() {
  auto entity = std::make_shared<Entity>(11);

  std::cout << "Entity pointer:" << entity.get() << std::endl;
  auto raw_ptr = entity.use_count();
  std::cout << "raw pointer:   " << raw_ptr << std::endl;
}

void interesting() {
  std::vector<int> pointer_to_ints{11, 12, 13};

  auto itr = pointer_to_ints.begin();

  std::cout << "Pointer address is: " << &pointer_to_ints << std::endl;
  while (itr != pointer_to_ints.end()) {
    std::cout << "Address " << &itr << " ";
    std::cout << "value " << *itr << std::endl;
    itr++;
  }
}
int main() {
  foo();
  interesting();
}
