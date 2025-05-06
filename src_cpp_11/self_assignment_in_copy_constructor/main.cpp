#include <iostream>
#include <memory>

class Table {
public:
  std::shared_ptr<int> ptr;

  Table() : ptr(std::make_shared<int>(11)) {
    std::cout << "Table constructor \n";
  }

  ~Table() { std::cout << "Table Destructor \n"; }

  // Default copy and move constructors
  Table(const Table &) = default;
  Table &operator=(const Table &) = default;
  Table(Table &&) noexcept = default;
  Table &operator=(Table &&) noexcept = default;
};

class Entity {
private:
  std::shared_ptr<Table> table_;

public:
  Entity() : table_(std::make_shared<Table>()) {}

  Entity &operator=(Entity const &obj) noexcept {
    if (this == &obj) {
      std::cout << "Both objects are Equal \n";
      return *this;
    }

    table_ = std::make_shared<Table>(*obj.table_); // Deep copy of Table
    return *this;
  }

  void print() { std::cout << "Value: " << *table_->ptr << std::endl; }
};

int main() {
  Entity first;
  Entity second;

  first = second;

  first.print();
  second.print();
}
