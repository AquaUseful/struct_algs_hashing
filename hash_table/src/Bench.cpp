#include "Bench.hpp"
#include "OpenAddressHashmap.hpp"

#include <algorithm>
#include <bits/chrono.h>
#include <chrono>
#include <cstddef>

Bench::Bench(size_t size, value_t max_val)
    : m_fill_values(size),
      m_test_values(size), fill_max{max_val}, test_max{max_val * 2}, m_rdev{} {}

void Bench::refill() {
  m_rgen.seed(m_rdev());
  {
    rand_distrib_t fill_dist(0, fill_max);
    const auto filler = [this, &fill_dist]() { return fill_dist(m_rgen); };
    std::generate(m_fill_values.begin(), m_fill_values.end(), filler);
  }
  {
    rand_distrib_t test_dist(0, test_max);
    const auto filler = [this, &test_dist]() { return test_dist(m_rgen); };
    std::generate(m_test_values.begin(), m_test_values.end(), filler);
  }
}
