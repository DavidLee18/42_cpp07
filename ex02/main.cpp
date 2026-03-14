#include "Array.h"
#include <iostream>

int main() {
  try {
    Array<short> a;
    std::cout << a[2] << std::endl;
  } catch (std::exception &e) {
    std::cerr << "error from a: " << e.what() << std::endl;
  }
  Array<int> b(8);
  for (size_t i = 0; i < 8; i++) {
    std::cout << b[i] << ", ";
  }
  std::cout << std::endl;

  Array<int> c(8);
  for (size_t i = 0; i < 8; i++) {
    c[i] = static_cast<int>(i) + 1;
    std::cout << c[i] << ", ";
  }
  std::cout << std::endl;
  return 0;
}
