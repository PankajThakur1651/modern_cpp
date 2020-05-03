#include<iostream>
#include <vector>
#include<algorithm>
#include<iterator>
#include<numeric>
int main()
{
    std::vector<int> list_of_ints {1,2,3,4,5,6,7,8,9,10,11,12,13};
    std::vector<int> list_of_ints_second;
    list_of_ints_second.resize(list_of_ints.size());
    std::cout<<"size of second: "<<list_of_ints_second.size();
    auto it = lower_bound(list_of_ints.begin(), list_of_ints.end(), 3);
    std::cout<<*it<<std::endl;

    auto upper_bound_itr = upper_bound(list_of_ints.begin(), list_of_ints.end(), 4);
    std::cout<<*upper_bound_itr <<std::endl;

   std::copy(list_of_ints.begin(), list_of_ints.end(), list_of_ints_second.begin());

    for (auto i: list_of_ints_second)
    {
        std::cout<<"Value: "<<i <<std::endl;
    }

    std::copy(list_of_ints.begin(), list_of_ints.end(), std::ostream_iterator<int> (std::cout, ", "));
    
    std::vector<int> seq = {1,2,3,4,5,6};

    std::sort(seq.begin(), seq.end());

    auto itr = std::unique(seq.begin(), seq.end());
    std::cout<<"itr is pointing to: "<<*itr<<std::endl;
    for (const auto &i : seq)
    {
        std::cout<< i <<std::endl;
    }
    seq.resize(distance(seq.begin(), itr));

    auto value = std::accumulate(seq.begin(), seq.end(), 1, std::multiplies<int>());

    std::cout<< "value :" <<value<<std::endl;

}