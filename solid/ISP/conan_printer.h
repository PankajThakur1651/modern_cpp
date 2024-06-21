//
// Created by ubuntu on 21.06.24.
//

#ifndef MODERN_CPP_CONAN_PRINTER_H
#define MODERN_CPP_CONAN_PRINTER_H

#include "print.h"
class Conan_printer : public Print {
public:
  void print() override;

  int get_print_pools_detail() override;
};

#endif // MODERN_CPP_CONAN_PRINTER_H
