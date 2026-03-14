#ifndef ITER_H
#define ITER_H

#include <cstddef>
#include <iostream>

template <typename T> void iter(T *arr, const size_t len, void (*f)(T &)) {
  for (size_t i = 0; i < len; i++) {
    f(arr[i]);
  }
}

void add1(int &i) { i++; }

void print_out(long const &l) { std::cout << l << std::endl; }

#endif
