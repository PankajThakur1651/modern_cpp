//
// Created by ubuntu on 21.06.24.
//

#ifndef MODERN_CPP_PRINTER_SCANNER_H
#define MODERN_CPP_PRINTER_SCANNER_H
#include "print.h"
#include "scan.h"

class Printer_scanner : public Print, Scan {
public:
  void print() override;

  int get_print_pools_detail() override;

private:
  void scan_photo() override;

  void scan() override;
};

#endif // MODERN_CPP_PRINTER_SCANNER_H
