#include "iter.h"

int main() {
  int is[] = {3, 1, 4, 1, 5, 9, 2};
  iter(is, 7, add1);
  for (size_t i = 0; i < 7; i++) {
    std::cout << is[i] << ", ";
  }
  std::cout << std::endl;
  const long ls[] = {1, 4, 1, 4};
  iter(ls, 4, print_out);
  return 0;
}
