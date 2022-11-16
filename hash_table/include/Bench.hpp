#pragma once

#include <chrono>
#include <cstdint>
#include <iterator>
#include <random>
#include <vector>

#include "OpenAddressHashmap.hpp"

class Bench {
public:
  using oa_hashtable_t = OpenAddressHashmap;

  using size_t = std::size_t;
  using value_t = std::uint64_t;

  using rand_dev_t = std::random_device;
  using rand_gen_t = std::mt19937_64;
  using rand_distrib_t = std::uniform_int_distribution<value_t>;

  using value_array_t = std::vector<value_t>;

  using duration_t = std::chrono::milliseconds;

  using bench_result_t = struct BenchResult {
    duration_t time;
    double comparisons;
    size_t found_count;
  };

public:
  Bench(size_t, value_t);

  void refill();
  bench_result_t oa_bench();

private:
  const value_t fill_max;
  const value_t test_max;

  rand_dev_t m_rdev;
  rand_gen_t m_rgen;

  value_array_t m_fill_values;
  value_array_t m_test_values;
};