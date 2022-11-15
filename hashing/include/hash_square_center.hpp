#pragma once

#include <cmath>
#include <cstddef>
#include <cstdint>

inline constexpr std::uint64_t hash_midsquare(std::uint64_t key,
                                              std::uint64_t index_digits) {
  std::uint64_t square = key * key;
  std::uint64_t square_length = std::trunc(std::log10(square) + 1);
  std::uint64_t div = 1;
  for (auto i = 0; i < index_digits; div *= 10, ++i)
    ;
  std::uint64_t trunc = 1;
    for (auto i = 0; i < ((square_length - index_digits) / 2); trunc *= 10, ++i)
      ;
  return ((square / trunc) % div);
}
