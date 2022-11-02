#pragma once

#include <concepts>
#include <cstddef>

template <std::unsigned_integral KeyT, std::unsigned_integral DivT>
inline constexpr auto hash_division(const KeyT key, const DivT divisor) -> std::size_t {
  return key % divisor;
}
