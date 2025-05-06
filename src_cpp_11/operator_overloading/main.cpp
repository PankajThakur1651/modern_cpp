#include "Test.h"
#include <iostream>

int main() {
  Test t;
  auto x = t[3];

  std::cout << "x: " << x << std::endl;
  return 0;
}
