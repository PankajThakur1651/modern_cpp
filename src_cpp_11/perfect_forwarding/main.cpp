#include <iostream>
#include <memory>
#include <vector>

class Pan_vector {
  int size_;
  double *array_;

public:
  Pan_vector(int size) {
    size_ = size;
    array_ = new double[size_];
    for (int i = 0; i < size_; i++) {
      array_[i] = i * 2;
    }
  }

  void display() {
    // std::cout<<"Display \n";
  }

  Pan_vector(Pan_vector const &obj) {
    std::cout << "Copy constructor" << std::endl;
    size_ = obj.size_;
    array_ = new double[size_];

    for (int i = 0; i < size_; i++) {
      array_[i] = obj.array_[i];
    }
  }

  Pan_vector(Pan_vector &&obj) noexcept {
    std::cout << "Move constructor" << std::endl;
    size_ = obj.size_;
    array_ = obj.array_;
    obj.array_ = nullptr;
  }

  Pan_vector &operator=(Pan_vector const &obj) = delete;

  Pan_vector &operator=(Pan_vector &&obj) noexcept = delete;

  ~Pan_vector() { delete[] array_; }
};

Pan_vector CreatePanVector() { return Pan_vector(11); }

void foo(Pan_vector &pv) {
  std::cout << "foo&" << std::endl;
  pv.display();
}

void foo(Pan_vector &&pv) {
  std::cout << "foo &&" << std::endl;
  pv.display();
}

template <typename T> void relay(T &&a) {
  std::cout << "Relay" << std::endl;
  foo(std::forward<T>(a));
}

int main() {
  auto vec = CreatePanVector();
  relay(vec);
  relay(CreatePanVector());
}
