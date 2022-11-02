#pragma once

#include <concepts>
#include <cstddef>

template <std::unsigned_integral T> inline constexpr auto hash_division(const T key, const T divisor) -> std::size_t {
  return key % divisor;
}
