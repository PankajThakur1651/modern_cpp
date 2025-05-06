#ifndef TEST_H
#define TEST_H

#include <array>

class Test {
private:
  std::array<int, 5> first_array{1, 3, 5, 7, 9};

public:
  int &operator[](unsigned long i);
};

#endif
