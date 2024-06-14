#include <iostream>
#include <tuple>

using namespace std;

struct Test {

  int first_value;
  int second_value;
  float third_value;

  Test(int first, int second, float third)
      : first_value{first}, second_value{second}, third_value{third} {}

  Test(Test const &obj) = default;

  Test &operator=(Test const &obj) = default;

  Test(Test &&obj) noexcept = default;

  Test &operator=(Test &&obj) noexcept = default;
};

void with_modifiers();

tuple<Test, Test> get_test_values() {
  Test test_1(1, 2, 3);
  Test test_2(11, 12, 13);
  return std::make_tuple(test_1, test_2);
}

auto get_values() {
  auto values = std::make_tuple(1, 2, 3);
  return values;
}

void function_returning_tuple() {
  auto const [first_value, second_value, third_value] = get_values();
  cout << "first_value: " << first_value << "\t"
       << "second_value: " << second_value << "\t"
       << "third_value: " << third_value << " " << endl;
}

void with_simple_data_types() {
  auto const [value_1, value_2, value_3] = make_tuple(19, 20, 21);
  cout << "value_1: " << value_1 << "\t"
       << "value_2: " << value_2 << "\t"
       << "value_3: " << value_3 << " " << endl;
}

void with_UDT() {
  auto [test_1, test_2] = get_test_values();
  cout << "test_1 values: " << test_1.first_value << " " << test_1.second_value
       << " " << test_1.third_value << endl;

  cout << "test_2 values: " << test_2.first_value << " " << test_2.second_value
       << " " << test_2.third_value << endl;
}

void with_modifiers() {
  {
    pair values(0, 0);
    auto [first, second] = values;
    first = 10; // values does not change here
    cout << "First " << first << " value's first: " << values.first << endl;
  }

  {
    pair values(0, 0);
    auto &[first, second] = values;
    first = 10; // values will also change with this
    cout << "First " << first << " value's first: " << values.first << endl;
  }
}

// Structured bindings are a C++17 feature that allows you to bind multiple
// variables to the elements of a structured object,
//  such as a tuple or struct, in a single declaration
int main() {
  function_returning_tuple();
  with_simple_data_types();
  with_UDT();
  with_modifiers();
}
