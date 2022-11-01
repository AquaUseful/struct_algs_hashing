#pragma once

#include <cassert>
#include <concepts>
#include <cstddef>

template <std::unsigned_integral KeyT, std::floating_point CoefT>
requires std::convertible_to<KeyT, CoefT>
inline constexpr auto hash_multiplication(const KeyT key, const CoefT coef,
                                          const std::size_t index_count)
    -> std::size_t {
  assert((coef > 0) && (coef < 1));
  const auto mkey = key * coef;
  const auto frac = mkey - static_cast<KeyT>(mkey);
  return static_cast<std::size_t>(index_count * frac);
}