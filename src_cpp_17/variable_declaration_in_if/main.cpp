#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void in_cpp_14(std::vector<int> &vector_of_ints) {
  auto const itr = std::find(vector_of_ints.begin(), vector_of_ints.end(), 4);

  if (itr != vector_of_ints.end()) {
    *itr = 0x77; // decimal value of
  }
}

void in_cpp_17(std::vector<int> &vector_of_ints) {
  if (auto const itr = std::find(vector_of_ints.begin(), vector_of_ints.end(), 3);
      itr != vector_of_ints.end()) {
    *itr = 333;
  }
}

void print_vector(std::string const &cpp_version, std::vector<int> const &vec) {
  std::cout << "Cpp Version: " << cpp_version << std::endl;
  for (auto const &it : vec) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
}
int main() {
  std::vector<int> vec_of_ints_for_cpp_17{1, 3, 5, 7, 9};
  std::vector<int> vec_of_ints_for_cpp_14{2, 4, 6, 8, 10};
  in_cpp_14(vec_of_ints_for_cpp_14);
  in_cpp_17(vec_of_ints_for_cpp_17);

  print_vector("C++14", vec_of_ints_for_cpp_14);
  print_vector("C++17", vec_of_ints_for_cpp_17);
}