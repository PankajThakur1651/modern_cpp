#include <iostream>

class Vector {
public:
    Vector(int size) : ptr_{new int[size]}, size_{size} {}

    ~Vector() {
        delete[] ptr_;
    }

    void push_back(int x) {
        if (index_ >= size_) {
            std::cerr << "Error: Vector overflow\n";
            return;
        }
        ptr_[index_++] = x;
    }

    void print() const {
        for (int i = 0; i < index_; ++i) {
            std::cout << "Value is: " << ptr_[i] << " ";
        }
        std::cout << std::endl;
    }

    int get_size() const { return size_; }
    int get_index() const { return index_; }
    int* get_data() const { return ptr_; }

private:
    int size_;
    int index_{0};
    int* ptr_;
};


int main() {
    Vector v{12};
    for (int i = 0; i < 12; i++) {
        v.push_back(i);
    }

    std::cout << "Size is: " << v.get_size() << std::endl;
    std::cout << "Index is: " << v.get_index() << std::endl;

    int* ptr = v.get_data();
    for (int i = 0; i < v.get_index(); i++) {
        std::cout << "i: " << *(ptr + i) << " ";
    }
    std::cout << std::endl;
}
