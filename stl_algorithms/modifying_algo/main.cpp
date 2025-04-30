#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

/*
 *
 * copy , move, remove, transform, swap, fill, remove, replace, erase
 */


struct Test {
    int a_;

    Test(int a) : a_{a} {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~Test() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    bool operator<(Test const &obj) const {
        return a_ < obj.a_;
    }
};


std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};
std::vector<int> orig_vector{vec};
std::vector<int> vec_2{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

template<class T>
void print_vector(T a) {
    for (auto const &val: a) {
        std::cout << " " << val << " ";
    }
    std::cout << std::endl;
}


void copy_elements() {
    std::copy_if(vec.begin(), vec.end(), vec_2.begin(), [](int x) {
        return x > 2;
    });

    print_vector(vec_2);
    //copy_if,  copy_n, copy_backward
}

void move_elements() {

}

void transform() {
    std::vector<int> local_vec{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> local_vec_2{11, 12, 13, 14, 15};

    std::transform(local_vec.begin(), local_vec.end(), std::back_inserter(local_vec_2), [](auto x) {
        return x - 1;
    });

    print_vector(local_vec_2);
}

void swap() {

}

void fill() {

}

void replace() {

}

void remove() {
    std::vector<int> local_vec{1, 2, 3, 4, 5, 6, 7, 8, 7, 7, 8};
    std::cout << "Size of local Vector is: " << local_vec.size() << std::endl;
    auto itr = std::remove(local_vec.begin(), local_vec.end(), 7);
    local_vec.erase(itr, local_vec.end());
    print_vector(local_vec);
    std::cout << "Size of local Vector is: " << local_vec.size() << std::endl;
}

int main() {

    copy_elements();
    move_elements();
    transform();
    swap();
    remove();

    std::map<Test, int> test_;
    test_[Test{0}] = 1;

}