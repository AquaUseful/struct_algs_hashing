#pragma once

#include <atomic>
#include <cassert>
#include <concepts>
#include <cstddef>

inline constexpr std::uint64_t hash_wrapping(std::uint64_t key,
                                             std::uint64_t div) {
  std::uint64_t acc{0};
  while (key > 0) {
    acc += key % div;
    key /= div;
  }
  return acc % div;
}
