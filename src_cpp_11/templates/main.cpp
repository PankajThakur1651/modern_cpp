#include <iostream>
#include <vector>

namespace specialization {
    template<typename T>
    void function(T a) {
        std::cout << "Value of a in Generic : " << a << std::endl;
    }

    template<>
    void function(char a) {
        std::cout << "Regular function : " << a << std::endl;
    }
}


namespace partial_specialization {
    template<typename T, typename U>
    class Pair {
    public:
        void print() {
            std::cout << "Generic Pair\n";
        }
    };


    template<typename T>
    class Pair<T, int> {
    public:
        void print() {
            std::cout << "Partial specialization where second type is int\n";
        }
    };

}

int main() {
    specialization::function(11);
    specialization::function('c');

    partial_specialization::Pair<int, int> first_pair;
    first_pair.print();
    partial_specialization::Pair<char, float> second_pair;
    second_pair.print();
    return 0;
}