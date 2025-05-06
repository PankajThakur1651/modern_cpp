#include <algorithm>
#include <array>
#include <future>
#include <iostream>

int main() {
  const int size = 10;
  std::array<int, size> ids{11, 2, 1, 4, 5, 9, 6, 3, 2, 1};

  std::sort(ids.begin(), ids.end(), [](int x, int y) { return x > y; });
}
