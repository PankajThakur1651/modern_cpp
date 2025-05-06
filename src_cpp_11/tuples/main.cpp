#include <iostream>
#include <tuple>

using namespace std;

std::tuple<int, std::string, int> get_value() {
  auto value = std::make_tuple(1, std::string("test"), 1);

  return value;
}

int main() {
  std::tuple<int, std::string, float> tup(11, "Pankaj Thakur", 21.7f);
  std::cout << "Before change now tuple's first element is " << get<0>(tup)
            << std::endl;

  get<0>(tup) = 121;
  std::cout << "After change now tuple's first element is " << get<0>(tup)
            << std::endl;

  std::tuple<int, string, int> values = (get_value());

  std::cout << (get<0>(values)) << std::endl;
}
