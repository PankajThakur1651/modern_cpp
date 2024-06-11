#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

struct Person {
  std::string name;
  int age;
  int pin_code_address;
};

std::vector<Person> get_persons() {
  std::vector<Person> person{
      {"Pankaj", 12, 11111}, {"Thakur", 13, 11111}, {"Rahul", 10, 11234}};

  return person;
}
void minimum_element() {
  auto persons = get_persons();
  auto itr = std::min_element(
      persons.begin(), persons.end(),
      [](Person &p1, Person &p2) { return (p1.age < p2.age); });

  std::cout << "Age is " << itr->age << std::endl;
}

void maximum_element() {
  auto persons = get_persons();
  auto itr =
      std::max_element(persons.begin(), persons.end(),
                       [](Person p1, Person p2) { return (p1.age < p2.age); });

  std::cout << "Age is " << itr->age << std::endl;
}
void total_age() {
  auto persons = get_persons();
  int sum = std::accumulate(persons.begin(), persons.end(), 0,
                            [](int i, Person const &p) { return i + p.age; });
  std::cout << "sum is: " << sum << std::endl;
}
int main() {

  minimum_element();
  maximum_element();
  total_age();
}
