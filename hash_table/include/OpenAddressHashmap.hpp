#pragma once

#include <concepts>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <vector>

#include "hash.hpp"
#include "hash_multiplication.hpp"
#include "hash_wrapping.hpp"

class OpenAddressHashmap {
public:
  using size_t = std::size_t;
  using value_t = std::uint64_t;

  using cell_t = struct Cell {
    value_t value{0};
    bool free{true};
    bool search_skip{false};
  };

  using search_result_t = struct SearchResult {
    bool found;
    size_t comparisons;
  };

  using cell_array_t = std::vector<cell_t>;

  using hash_func_t = class HashFunc {
  public:
    HashFunc(size_t);

    value_t operator()(value_t);

  private:
    size_t m_index_count;
  };

public:
  OpenAddressHashmap(size_t);

  void insert(value_t);
  search_result_t search(value_t);

private:
  hash_func_t m_hash_func;
  cell_array_t m_cells;
};