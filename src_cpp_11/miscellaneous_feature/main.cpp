#include <iostream>
#include <memory>

void static_assert_usage() {
  // compile Time check
  static_assert(4 <= sizeof(int), "Integers are too small");
}
int main() { static_assert_usage(); }
