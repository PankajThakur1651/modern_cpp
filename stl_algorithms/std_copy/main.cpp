#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <vector>

void copy_list() {
  std::list<int> list_1{1, 2, 3};
  std::list<int> list_2{4, 5, 6};
  std::copy(list_1.begin(), list_1.end(), std::back_inserter(list_2));
  std::cout << "Elements in list2: " << std::endl;
  for (auto const &value : list_2) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}

void copy_vector() {
  std::vector<int> vec_1{1, 2, 3};
  std::vector<int> vec_2{4, 5, 6};

  std::copy(vec_1.begin(), vec_1.end(), std::back_inserter(vec_2));
  std::cout << "Elements in Vec2: " << std::endl;
  for (auto const &value : vec_2) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}
void copy_map() {
  std::map<int, int> map_1{{1, 2}, {3, 4}};
  std::map<int, int> map_2{{5, 6}, {7, 8}};

  //    std::copy(map_1.begin(), map_1.end(), std::inserter(map_2,
  //    map_2.end()));
  map_2.insert(map_1.begin(), map_1.end());
  std::cout << "Elements in Vec2: " << std::endl;
  for (auto const &value : map_2) {
    std::cout << value.first << " ";
  }
  std::cout << std::endl;
}

int main() {
  copy_vector();
  copy_list();
  copy_map();
}
