//
// Created by ubuntu on 21.06.24.
//

#include "xerox_work_center.h"
#include <iostream>

void xerox_work_center::print() { std::cout << __FUNCTION__ << std::endl; }

int xerox_work_center::get_print_pools_detail() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return 0;
}

void xerox_work_center::fax() { std::cout << __FUNCTION__ << std::endl; }

void xerox_work_center::internet_fax() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void xerox_work_center::scan_photo() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void xerox_work_center::scan() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}
