#include <iostream>
#include <string>

class Aclass {
private:
  int first_member;
  int second_member;

public:
  void show() {
    std::cout << "First Member: " << first_member << std::endl;
    std::cout << "Second Member: " << second_member << std::endl;
  }
};

int main() {

  Aclass object;
  int *ptr = reinterpret_cast<int *>(&object);
  *ptr = 11;
  ptr++;
  *ptr = 99;
  ptr--;

  object.show();
  Aclass *object2 = reinterpret_cast<Aclass *>(ptr);
  if (object2) {
    object2->show();
  }
}
