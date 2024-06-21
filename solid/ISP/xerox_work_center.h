//
// Created by ubuntu on 21.06.24.
//

#ifndef MODERN_CPP_XEROX_WORK_CENTER_H
#define MODERN_CPP_XEROX_WORK_CENTER_H
#include "fax.h"
#include "print.h"
#include "scan.h"
class xerox_work_center : public Print, Scan, Fax {
public:
  void print() override;

  int get_print_pools_detail() override;

  void fax() override;

  void internet_fax() override;

  void scan_photo() override;

  void scan() override;

public:
};

#endif // MODERN_CPP_XEROX_WORK_CENTER_H
