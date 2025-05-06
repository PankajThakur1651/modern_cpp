#include <iostream>
#include <memory>

class Test {
public:
  Test() {
    data_ = ++value;
    std::cout << "Test constructor \n";
  }

  ~Test() { std::cout << "Test Destructor \n"; }

  void print_member() { std::cout << "data_ : " << data_ << std::endl; }

private:
  int data_{};
  static int value;
};

int Test::value = 0;

auto return_type_deduction(int x) {
  if (x < 5) {
    return x;
  } else {
    return x + 10;
  }
}

void make_unique_feature() {
  auto const test =
      std::make_unique<Test>(); // std::make_unique<Test>() is new in cpp14
  test->print_member();
}

// auto specifier in the parameter list, enabling polymorphic lambdas
void generic_lambda_expression() {
  auto identity = [](auto x) { return x; };
  [[maybe_unused]] int three = identity(3);

  std::cout << "Three is " << three << std::endl;
}

void decltype_auto() {
  const int const_value = 10;
  [[maybe_unused]] decltype(auto) alias_to_const_value = const_value;

  const int value = 10;

  decltype(auto) ref = value;
  std::cout << "reference value is: " << ref << std::endl;

  static_assert(std::is_same<const int &, decltype(ref)>::value == 0, "");
}

void binary_literals() {
  auto value = 0b110;
  std::cout << "Binary value is " << value << std::endl;
}

int factory(int i) { return i * 10; }

void lambda_capture_initializer(){

};

void cpp_14_language_feature() {
  binary_literals();
  make_unique_feature();
  generic_lambda_expression();
  return_type_deduction(11);
  decltype_auto();
  lambda_capture_initializer();
}

int main() { cpp_14_language_feature(); }
