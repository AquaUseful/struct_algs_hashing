#pragma once

#include <cmath>
#include <concepts>
#include <cstddef>
#include <math.h>

template <std::unsigned_integral T>
requires std::convertible_to<T, double> || std::convertible_to<T, float> ||
    std::convertible_to<T, long double>
inline constexpr auto hash_square_center(const T key,
                                         const std::size_t index_digits)
    -> std::size_t {
  const auto square = key * key;
  const auto square_length = std::trunc(std::log10(square));
  return (square / (square_length / 2)) % index_digits;
}