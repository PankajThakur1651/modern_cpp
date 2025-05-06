#include <iostream>
#include <map>
#include <memory>

void exception() {
  //    try {
  //        [[maybe_unused]] auto value =10;
  //    }
  //    catch (int x)
  //    {
  //
  //    }
}

class Base {

public:
  virtual ~Base() = default;
};

class Derived : public Base {};

void no_rtti() {
  //    auto base_obj = std::make_shared<Base>();
  //
  //    [[maybe_unused]] auto pDerived = dynamic_cast<Derived*>(base_obj.get());
}

void about_casts() {

  int a = -7;
  auto b = static_cast<uint8_t>(a);
  std::cout << "b: " << uint64_t(b) << std::endl;
}

int main() {
  exception(); // program does not compile as exception is disabled
  no_rtti();   //
  // c++ compilers are as good as the cC compilers ( Gcc, Clang, MSVC, INTEL
  // compiler) c++ compilers are not as widely supported as C compilers on
  // embedded platforms (True)

  about_casts();
}
