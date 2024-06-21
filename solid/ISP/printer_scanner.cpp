//
// Created by ubuntu on 21.06.24.
//

#include "printer_scanner.h"
#include <iostream>
void printer_scanner::print() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

int printer_scanner::get_print_pools_detail() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return 0;
}

void printer_scanner::scan_photo() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void printer_scanner::scan() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
