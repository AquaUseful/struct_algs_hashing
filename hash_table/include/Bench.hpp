#pragma once

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iterator>
#include <random>
#include <vector>

#include "ChainHashmap.hpp"
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

  using duration_t = std::chrono::microseconds;

  using bench_result_t = struct BenchResult {
    duration_t time;
    double comparisons;
    size_t found_count;
  };

public:
  Bench(size_t, value_t);

  void refill();

  template <typename HashMapT> bench_result_t bench() {
    HashMapT hashmap(m_test_values.size());
    const auto filler = [&hashmap](const value_t &v) { hashmap.insert(v); };
    std::for_each(m_fill_values.cbegin(), m_fill_values.cend(), filler);

    bench_result_t res{};
    const auto searcher = [&hashmap, &res](const value_t &val) {
      const auto sres = hashmap.search(val);
      res.found_count += (sres.found ? 1 : 0);
      res.comparisons += sres.comparisons;
    };
    const auto start = std::chrono::high_resolution_clock::now();
    std::for_each(m_test_values.cbegin(), m_test_values.cend(), searcher);
    const auto end = std::chrono::high_resolution_clock::now();

    res.comparisons /= m_test_values.size();

    res.time = std::chrono::duration_cast<duration_t>(end - start);
    return res;
  }

private:
  const value_t fill_max;
  const value_t test_max;

  rand_dev_t m_rdev;
  rand_gen_t m_rgen;

  value_array_t m_fill_values;
  value_array_t m_test_values;
};