#include <iostream>
#include <vector>
#include <deque>
#include <memory>

class Person {
public:
    // Constructor
    Person(std::string name) : p_name_(std::make_shared<std::string>(name)) {}

    void print_name() const {
        std::cout << "Name is: " << *p_name_ << std::endl;
    }

private:
    std::shared_ptr<std::string> p_name_;
};


int main() {
    std::vector<Person> persons;
    persons.push_back(Person("Pankaj"));
    persons.push_back(Person("Thakur"));

    persons.emplace_back("raja");

    for (auto const &person: persons) {
        person.print_name();
    }
}


