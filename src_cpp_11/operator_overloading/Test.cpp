#include "Test.h"
#include <stdexcept>

int &Test::operator[](unsigned long i) {
  if (i >= first_array.size()) {
    throw std::out_of_range("Index out of bounds");
  }

  return first_array[i];
}
