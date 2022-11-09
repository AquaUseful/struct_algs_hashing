#pragma once

#include <cassert>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <cstdint>

inline constexpr std::uint64_t hash_multiplication(std::uint64_t key,
                                                   std::double_t coef,
                                                   std::uint64_t index_count) {
  assert((coef > 0) && (coef < 1));
  std::double_t mkey = key * coef;
  std::double_t frac = mkey - static_cast<std::uint64_t>(mkey);
  return static_cast<std::uint64_t>(index_count * frac);
}
