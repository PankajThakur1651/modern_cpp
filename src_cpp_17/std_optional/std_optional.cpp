#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>

std::optional<bool> give_square_root(int x) {
  if (x != 0) {
    return 3 * 3;
  }
  return std::nullopt;
}

void optional_example() {
  std::optional<int> int_optional = give_square_root(3);
  if (int_optional.has_value()) {
    std::cerr << "Have value " << int_optional.value() << std::endl;
  }

  int_optional = give_square_root(0);
  if (!int_optional.has_value()) {
    std::cerr << "Has no value " << std::endl;
  }
  int_optional.reset();
}

std::optional<std::string> read_files(std::string const &file_name) noexcept {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    return std::nullopt;
  }
  std::string contents((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
  return contents;
}
void one_more_example() {
  std::string const file_name = "example.txt";
  auto file_contents = read_files(file_name);

  std::cerr << file_contents.value();
}

int main() {
  optional_example();
  one_more_example();
}
