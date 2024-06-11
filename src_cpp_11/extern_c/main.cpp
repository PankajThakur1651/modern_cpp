#include <iostream>

static int static_variable{};

extern "C" {
#include "one_c_file.h"
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  func();
  return 0;
}
