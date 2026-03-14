#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <exception>
#include <new>
#include <stdexcept>

template <typename T> class Array {
  T *ptr;
  size_t len;

public:
  Array() : ptr(NULL), len(0) {}
  Array(unsigned int l) : ptr(new (std::nothrow) T[l]), len(l) {
    if (ptr == NULL)
      throw std::runtime_error("alloc failed");
    for (size_t i = 0; i < len; i++) {
      ptr[i] = 0;
    }
  }
  Array(Array const &other)
      : ptr(new (std::nothrow) T[other.len]), len(other.len) {
    if (ptr == NULL)
      throw std::runtime_error("alloc failed");
    else {
      for (size_t i = 0; i < len; i++) {
        ptr[i] = other.ptr[i];
      }
    }
  }
  ~Array() {
    if (ptr)
      delete[] ptr;
  }
  Array &operator=(Array const &other) {
    if (this != &other) {
      if (ptr)
        delete[] ptr;
      ptr = new (std::nothrow) T[other.len];
      if (ptr == NULL)
        throw std::runtime_error("alloc failed");
      len = other.len;
      for (size_t i = 0; i < len; i++) {
        ptr[i] = other.ptr[i];
      }
    }
    return *this;
  }

  size_t size() const { return len; }
  T &operator[](size_t i) {
    return i < len ? ptr[i] : throw std::out_of_range("out of range");
  }
};

#endif
