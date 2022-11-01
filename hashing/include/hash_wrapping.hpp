#pragma once

#include <cassert>
#include <concepts>
#include <cstddef>

template <std::unsigned_integral KeyT>
inline constexpr auto hash_wrapping(KeyT key, std::size_t index_digits)
    -> std::size_t {
  assert(index_digits > 0);
  KeyT divisor = 1;
  for (; index_digits > 0; --index_digits) {
    divisor *= 10;
  };
  KeyT accumulator{0};
  while (key > 0) {
    accumulator += key % divisor;
    key /= divisor;
  }
  accumulator %= divisor;
  return accumulator;
}
