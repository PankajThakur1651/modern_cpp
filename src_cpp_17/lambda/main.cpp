#include <iostream>
#include <string>
#include <tuple>

using namespace std;

struct Instrumented_class {
public:
  explicit Instrumented_class(std::string id) : id_{id} {}

  Instrumented_class(Instrumented_class const &obj) = default;

  Instrumented_class &operator=(Instrumented_class const &obj) = default;

  Instrumented_class(Instrumented_class &&obj) noexcept = default;

  Instrumented_class &operator=(Instrumented_class &&obj) noexcept = default;

  std::string get_id() const { return id_; }

protected:
  std::string id_;
};

void capture_by_value() {
  Instrumented_class obj_1("Pankaj");
  Instrumented_class obj_2{"Thakur"};

  auto lambda = [=] { return make_tuple(obj_1.get_id(), obj_2.get_id()); };
  auto [id1, id2] = lambda();
  cout << "Size of lambda is When capture is by val: " << sizeof(lambda)
       << std::endl;
}

void capture_by_reference() {
  Instrumented_class obj_1("Pankaj");
  Instrumented_class obj_2{"Thakur"};

  auto lambda = [&] { return make_tuple(obj_1.get_id(), obj_2.get_id()); };
  auto [id1, id2] = lambda();
  cout << "Size of lambda is When capture is by ref: " << sizeof(lambda)
       << std::endl;
}

int main() {
  capture_by_reference();
  capture_by_value();
}
