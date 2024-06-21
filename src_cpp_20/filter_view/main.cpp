#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

void print(std::ranges::input_range auto const &collection) {
  for (auto const &value : collection) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}

void about_views() {
  vector<int> vector_of_int{1, 2, 3, 4};
  set<int> set_of_int{5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  print(vector_of_int);
  print(set_of_int);

  print(views::take(vector_of_int, 3));
  print(views::take(set_of_int, 4));

  print(vector_of_int | views::take(3));
  print(set_of_int | views::take(6) |
        views::transform([](auto v) { return std::to_string(v) + "'s"; }));
}

void pipeline_of_range_adaptors() {
  std::map<std::string, int> authors{{"Bjarne", 1970},
                                     {"Herb", 1976},
                                     {"Scott", 1990},
                                     {"Andrei", 1981},
                                     {"Nicolai", 2010}};

  namespace vws = std::views;
  for (auto const &elem :
       authors | vws::filter([](auto const &y) { return y.second <= 2010; }) |
           vws::take(3) | vws::keys) {
    std::cout << elem << std::endl;
  }
}

void pipeline_of_view() {
  auto v = std::views::iota(1);

  for (auto const &val :
       v | std::views::filter([](auto val) { return val % 3 == 0; }) |
           std::views::drop(3) | std::views::take(8) |
           std::views::transform(
               [](auto value) { return std::to_string(value) + "s"; })) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

// using a pipeline to Modify elements

auto non_empty_view = std::views::filter([](auto const &rg) {
  std::cout << std::boolalpha << rg.empty() << std::endl;
  return !rg.empty();
});

void pipeline_to_modify_elements() {
  std::vector<std::string> words{"tic", "tac", "toe", "", "ok"};

  print(words);

  for (auto &elem : words | non_empty_view) {
    elem = elem + "_s";
  }
  print(words);
}

// from cpp con https://www.youtube.com/watch?v=c1gfbbE2zts
int main() {
  //    about_views();
  //    pipeline_of_range_adaptors();

  pipeline_of_view();
  pipeline_to_modify_elements();
}
