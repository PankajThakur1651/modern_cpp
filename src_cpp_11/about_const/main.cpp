#include <iostream>
#include <vector>


void const_basics() {
    int const value =9;
   [[maybe_unused]] int const* ptr_1 = &value; // data is const , ptr_1 is not


    ptr_1++;
    auto value_2 =9;
    [[maybe_unused]]int * const ptr_2 = &value_2; // ptr_2 is const but not data it is pointing to

    // ptr_2++; is not allowed

    int const value_3 = 123;
    [[maybe_unused]]int const *const ptr_3 = &value_3; // // data is const , ptr_3 is also const


    int const i =10;
    const_cast<int&>(i) = 6;

    std::cout<<"Now i is " <<i <<std::endl;
}

class Big_array
{
    std::vector <int> vec_;
    mutable int access_counter_;
public:
    Big_array(std::vector<int> vec, int initial_value = 0):vec_(std::move(vec)), access_counter_(initial_value)
    {

    }

    int get_item(int64_t const index) const {
        access_counter_++;

        if (index >= 0 && index < static_cast<int64_t>(vec_.size())) {
            std::cerr << "vec_.size() " << vec_.size() << std::endl;
            return vec_[index];
        }

        throw std::runtime_error("Invalid index");
    }
};

int main()
{
    const_basics();
    auto const vec = std::vector<int> {1,2,3,4,5};
    Big_array b {vec, 0};
    std::cout<<b.get_item(0);
}


