#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> const vec{1, 2, 4, 11, 10, 12, 8, 6};
// Count, min, max , compare , Linear Search, Attribute

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

    std::cout << *find_if_not_itr;
}

int main() {
    count_usage();
    count_if_usage();
    min_max_usage();
    linear_search();
}