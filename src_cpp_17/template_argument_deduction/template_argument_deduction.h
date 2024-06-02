//
// Created by ubuntu on 01.06.24.
//

#ifndef MODERN_CPP_TEMPLATE_ARGUMENT_DEDUCTION_H
#define MODERN_CPP_TEMPLATE_ARGUMENT_DEDUCTION_H

#include <iostream>
using namespace std;
template <typename T> class template_argument_deduction final {
public:
  explicit template_argument_deduction(T fa);

  void display_all_member();

private:
  T first_argument;
};

#endif // MODERN_CPP_TEMPLATE_ARGUMENT_DEDUCTION_H
