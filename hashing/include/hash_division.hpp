#pragma once

#include <concepts>
#include <cstddef>
#include <cstdint>

inline constexpr std::uint64_t hash_division(std::uint64_t key,
                                             std::uint64_t divisor) {
  return key % divisor;
}