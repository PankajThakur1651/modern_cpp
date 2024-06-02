//
// Created by ubuntu on 01.06.24.
//

#include "template_argument_deduction.h"

template <typename T>
template_argument_deduction<T>::template_argument_deduction(T fa) {

  first_argument = fa;
}

template <typename T>
void template_argument_deduction<T>::display_all_member() {
  std::cout << "First Argument is: " << first_argument << std::endl;
}
// Explicit instantiation the class for int and can be extended , else
// compilation fails in main.cpp
template class template_argument_deduction<int>;
