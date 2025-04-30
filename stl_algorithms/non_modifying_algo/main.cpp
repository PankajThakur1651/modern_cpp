#include <iostream>
#include <algorithm>
#include <vector>


std::vector<int> const vec{1, 2, 4, 11, 10, 24, 12, 8, 6, 24, 24};
// Count, min, max , compare , Linear Search, Attribute, find, find_if, find_if_not, search_n

void count_if_usage() {
    auto even_count = std::count_if(vec.begin(), vec.end(), [](int x) {
        return (x % 2 == 0);
    });

    std::cout << "Even Number count is: " << even_count << std::endl;
}

void count_usage() {
    auto presence_count = std::count(vec.begin(), vec.end(), 11);
    std::cout << "Number 11 presence is " << presence_count << " times " << std::endl;
}

void min_max_usage() {
    auto const min_itr = std::min_element(vec.begin(), vec.end());
    std::cout << "Minimum element is: " << *min_itr << std::endl;


    auto const max_itr = std::max_element(vec.begin(), vec.end());
    std::cout << "max element is: " << *max_itr << std::endl;

    auto const min_max_itr = std::minmax_element(vec.begin(), vec.end());
    std::cout << "Minimum element is: " << *min_max_itr.first << std::endl;
    std::cout << "max element is: " << *min_max_itr.second << std::endl;
}

void linear_search() {
    auto itr = std::find(vec.begin(), vec.end(), 11);
    if (itr != vec.end()) {
        std::cout << "Element found " << *itr << std::endl;
    }

    auto find_if_not_itr = std::find_if_not(vec.begin(), vec.end(), [](int x) {
        return x <= 4;
    });

    std::cout << *find_if_not_itr << std::endl;
}

void about_find() {
    auto itr = std::find(vec.begin(), vec.end(), 3);
    if (itr != vec.end()) {
        std::cout << *itr << std::endl;
    }

    //find_if
    // find_if_not

    itr = search_n(vec.begin(), vec.end(), 2, 24);
    if (itr != vec.end()) {
        std::cout << "consecutive 1 item of 24 found " << std::endl;
    }
}

//all_of, any_of, none_of
void all_none_any_of_algos() {
    auto condition = std::all_of(vec.begin(), vec.end(), [](int value) {
        return value >= 1;
    });

    std::cout << "condition is: " << condition << std::endl;

    condition = std::any_of(vec.begin(), vec.end(), [](int value) {
        return value % 2 ==0;
    });

    std::cout << "any of modulus is 0: " << condition << std::endl;

    condition = std::none_of(vec.begin(), vec.end(), [](int value) {
        return value % 2 ==0;
    });

    std::cout << "none of modulus is 0: " << condition << std::endl;
}

int main() {
    count_usage();
    count_if_usage();
    min_max_usage();
    linear_search();
    about_find();
    all_none_any_of_algos();
}