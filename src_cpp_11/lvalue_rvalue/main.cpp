#include <iostream>
void print_name(std::string &&name) {
  std::cout << "Rvalue reference " << name << std::endl;
}

void print_name(std::string const &name) {
  std::cout << "Lvalue reference " << name << std::endl;
}

int main() {
  std::string first_name = "PaNkAj";
  std::string last_name = "ThAkUr";
  std::string full_name = first_name + " " + last_name;
  print_name(full_name);
  print_name(first_name + " " + last_name);

  return 0;
}
