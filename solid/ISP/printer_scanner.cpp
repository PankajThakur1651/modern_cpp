//
// Created by ubuntu on 21.06.24.
//

#include "Printer_scanner.h"
#include <iostream>
void Printer_scanner::print() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

int Printer_scanner::get_print_pools_detail() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return 0;
}

void Printer_scanner::scan_photo() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Printer_scanner::scan() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
