#pragma once

#include <cstdint>
#include <forward_list>
#include <vector>

class ChainHashmap {
public:
  using size_t = std::size_t;
  using value_t = std::uint64_t;

  using chain_t = std::forward_list<value_t>;
  using chain_array_t = std::vector<chain_t>;

  using search_result_t = struct SearchResult {
    bool found;
    size_t comparisons;
  };

  using hash_func_t = class HashFunc {
  public:
    HashFunc(size_t);

    value_t operator()(value_t);

  private:
    size_t m_index_count;
  };

public:
  ChainHashmap(size_t);

  void insert(value_t);
  search_result_t search(value_t);

private:
  hash_func_t m_hash_func;
  chain_array_t m_chains;
};