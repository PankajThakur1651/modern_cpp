#include "composition.h"
#include <iostream>
int main() {
  auto house = House::Create_obect();
  // This is wrong, this was a test
  static auto const *const loader = new House(std::move(house));

  delete loader;
}