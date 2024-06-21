#include "conan_printer.h"
#include "printer_scanner.h"
#include "xerox_work_center.h"
#include <iostream>
using namespace std;

// No client should be forced to depend on the methods it does not use

// Techniques to identify violation of ISP
// 1. Fat interface
// 2. Interfaces with low Cohesion
// 3. Empty Method Implementation
//

int main() {
  xerox_work_center xerox_work_center_obj;
  xerox_work_center_obj.get_print_pools_detail();
  xerox_work_center_obj.scan();
}
