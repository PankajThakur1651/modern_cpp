#include "racing_car_lsp.h"
#include <iostream>
using namespace std;

/* Object should be replaceable with their subtypes without effecting the
 correctness of the program*/

int main() {
  lsp_good_example::Racing_car_lsp lsp;
  std::cout << lsp.get_interior_width() << std::endl;
}
