#include <iostream>

template <class Derived> // 1
class Animal {
public:
  Animal() = default;
  ~Animal() = default;
  friend Derived;

public:
  void make_sound() { static_cast<Derived &>(*this).make_sound(); }
};

class Sheep : public Animal<Sheep> { // 2
public:
  void make_sound() { std::cout << "baa" << std::endl; }
};

class Dog : public Animal<Dog> { // 3
public:
  void make_sound() { std::cout << "Bow Bow..." << std::endl; }
};

template <typename Derived> void print(Animal<Derived> &animal) {
  animal.make_sound();
}

/*
 *
 * Limitation of CRTP
 * 1. There is no common base class
 * 2. Everything is a template
 */
int main() {
  Animal<Sheep> sheep;
  print(sheep);

  Animal<Dog> dog;
  print(dog);
  return 0;
}
