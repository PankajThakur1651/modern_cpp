#include <iostream>
#include <tuple>
#include <set>
#include <cassert>

using namespace std;

struct S
{
    int n;
    std::string s;
    float d;

    friend bool operator<(const S& lhs, const S& rhs) noexcept
    {
        // compares lhs.n to rhs.n,
        // then lhs.s to rhs.s,
        // then lhs.d to rhs.d
        // in that order, first non-equal result is returned
        // or false if all elements are equal
        return std::tie(lhs.n, lhs.s, lhs.d) < std::tie(rhs.n, rhs.s, rhs.d);
    }
};

int main()
{
    std::set<S> my_set;
    S s {10, "tuple_data", 14.5f};
//    auto [iter, is_inserted] = my_set.insert(s);
//    if (is_inserted)
//    {
//        std::cerr<<"Value is inserted in tuple "<<is_inserted <<std::endl;
//    }
}