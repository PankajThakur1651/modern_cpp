#include <iostream>
#include <memory>
#include <string>

// Generic template for addition
template <typename T> T addition(T a, T b) {
  std::cout << "using generic template ";
  return a + b;
}

// Specialization for char type, returns concatenated string
template <> std::string addition<std::string>(std::string a, std::string b) {
  std::cout << "using template specialization ";
  // Concatenating characters as a string
  return a + b;
}

int main() {
  // Generic template addition
  std::cout << "Sum of 11 and 12 is " << addition(11, 12) << std::endl;
  std::cout << "Sum of 11.55 and 12.55 is " << addition(11.55, 12.55)
            << std::endl;

  // Template specialization for chars (concatenating them as a string)
  std::cout << "Sum of 'A' and 'B' is "
            << addition(std::string("ABCD"), std::string("EFGH"))
            << std::endl; // This will print "AB"

  return 0;
}
