#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    std::unordered_set<int> uset{12, 1, 2, 3, 6, 8};

    auto itr = uset.find(3);  // O(1)

    if (itr != uset.end()) {
        std::cout << "Element found" << std::endl;
    }


    itr = find(uset.begin(), uset.end(), 4);

    if (itr != uset.end()) {
        std::cout << "Element found" << std::endl; // O(n)
    }
}