#include <iostream>
#include <vector>

class Rule_of_five {
public:
  explicit Rule_of_five(int value) : ptr_(new int(value)) {}

  Rule_of_five(Rule_of_five const &obj) {

    ptr_ = new int;
    *ptr_ = *obj.ptr_;
  }

  Rule_of_five &operator=(Rule_of_five const &obj) {
    if (this != &obj) {
      delete ptr_;
      ptr_ = new int(*obj.ptr_);
    }
    return *this;
  }

  Rule_of_five(Rule_of_five &&obj) noexcept {
    ptr_ = obj.ptr_;
    obj.ptr_ = nullptr;
  }

  Rule_of_five &operator=(Rule_of_five &&obj) noexcept;

  ~Rule_of_five() {
    std::cout << "Deleted Now ..." << std::endl;
    delete ptr_;

    ptr_ = nullptr;
  }

  void print_ptr();

  auto get_ptr();

private:
  int *ptr_;
};

Rule_of_five &Rule_of_five::operator=(Rule_of_five &&obj) noexcept {
  if (this != &obj) {
    delete ptr_;
    ptr_ = obj.ptr_;
    obj.ptr_ = nullptr;
  }
  return *this;
}

void Rule_of_five::print_ptr() { std::cout << "ptr is: " << ptr_ << std::endl; }

auto Rule_of_five::get_ptr() { return ptr_; }

int main() {

  Rule_of_five real_object(11);
  auto first_copy = real_object;
  Rule_of_five real_object_2(11);
  real_object_2 = real_object;
}