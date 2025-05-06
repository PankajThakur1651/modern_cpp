#include <iostream>
#include <map>
#include <vector>
class Entry {
public:
  std::string name;
  int value;
};

Entry read_value(std::istream &is) {
  std::string name;
  int value;
  std::cout << "Enter the name and Value " << std::endl;
  is >> name >> value;
  return Entry{name, value};
}

int main() {
  // auto [n, v] = read_value(std::cin);

  std::map<std::string, int> values{{"Pankaj", 2}, {"Pankaj", 2}};

  std::cout << "Size of the map is " << values.size() << std::endl;
}