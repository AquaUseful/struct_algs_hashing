#pragma once

#include <cmath>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <math.h>

inline constexpr std::uint64_t hash_midsquare(std::uint64_t key,
                                              std::uint64_t index_digits) {
  std::uint64_t square = key * key;
  std::uint64_t square_length = std::trunc(std::log10(square));
  std::uint64_t div = 1;
  for (auto i = 0; i < index_digits; div *= 10, ++i)
    ;
  return (square / ((square_length - index_digits) / 2)) % div;
}
