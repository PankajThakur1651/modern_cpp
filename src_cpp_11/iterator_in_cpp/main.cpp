#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <list>
using namespace std;

// input iterators
void pure_input_iterator() {
    std::cout << "Enter numbers (Ctrl+D to stop):\n";
    std::istream_iterator<int> input_it(std::cin); // reads from cin
    std::istream_iterator<int> end; // default-constructed == end of stream

    std::cout << "I am here \n";
    while (input_it != end) {
        int value = *input_it; // read value
        value = *input_it;
        std::cout << "Read: " << value << "\n";
        ++input_it; // move to next input
    }
}

// output iterators
void pure_output_iterator() {
    std::vector<int> data = {10, 20, 30};
    std::ostream_iterator<int> output_it(std::cout, " "); // writes to cout with space separator

    std::cout << "Output: ";
    std::copy(data.begin(), data.end(), output_it); // output_iterator used by std::copy
    std::cout << "\n";
}

void forward_iterator_example() {
    std::forward_list<int> flist = {1, 2, 3, 4};

    std::cout << "Forward Iterator: ";
    auto itr = flist.begin();
    //--itr;  Error only forward iterator
    while (itr != flist.end()) {
        std::cout << " " << *itr;
        ++itr;
    }
}

void bidirectional_iterator_example() {
    std::list<int> list = {1, 2, 3, 4};
    std::cout << "forward Iterator: ";
    for (auto const &it: list) {
        std::cout << it << " ";
    }
    std::cout << " \n Backward Iterator: ";
    for (auto itr = list.rbegin(); itr != list.rend(); ++itr) {
        std::cout << *itr << " ";
    }
}

void random_access_iterator_example() {
    std::vector<int> data = {1, 2, 3, 4};
    std::cout << "\nRandom Access Iterator: ";
    std::cout << "data[0] = " << data[0] << "\n";
    auto itr = data.begin();
    itr = itr + 2;
    std::cout << "*(itr+2) = " << *itr << "\n";
    ++itr;
    std::cout << "*(itr+3) =" << *itr << std::endl;
}

class Test {
    int x;

public:
    explicit Test(int  const x) :x {x} {
        std::cout<<"Default constructor " <<std::endl;
    }

    Test(Test const &obj ) =delete;
    Test& operator = (Test const &obj ) =delete;

    Test(Test &&obj ) =delete;
    Test& operator = (Test &&obj ) =delete;


    int get_x() const {
        return x;
    }
};

void for_exercise() {
    std::list<Test> test_list;
    test_list.emplace_back(1);
    test_list.emplace_back(2);
    for_each(test_list.begin(), test_list.end(), [](Test const &value) {
        std::cout << "value: " << value.get_x() << std::endl;
    });
}

int main() {
    // pure_input_iterator();
    pure_output_iterator();
    forward_iterator_example();
    bidirectional_iterator_example();
    random_access_iterator_example();
    for_exercise();
}
