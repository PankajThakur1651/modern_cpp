#include <iostream>
#include <string>
#include <variant>

using namespace std;

struct lambda {
  template <typename T> void operator()(T const &param) { std::cout << param; }
};

template <typename T>
std::variant<int, double, std::string> get_value(T value) {

  std::variant<int, double, std::string> variant_holder;
  variant_holder = value;
  return variant_holder;
}

// Application of std::variant
// Handling Multiple Data Types:
int main() {
  // std::visit(lambda(), get_value(10));

  // Access the int
  if (holds_alternative<int>(get_value(12))) {
    cout << get<int>(get_value(12)) << endl;
  }

  // Access the double
  if (holds_alternative<double>(get_value(12.456))) {
    cout << get<double>(get_value(12.567)) << endl;
  }
  // Access the string
  if (holds_alternative<string>(get_value("Pankaj"))) {
    cout << get<string>(get_value("Thakur")) << endl;
  }
}
