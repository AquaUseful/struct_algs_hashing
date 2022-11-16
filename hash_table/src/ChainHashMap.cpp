#include "ChainHashmap.hpp"

#include <algorithm>
#include <cmath>
#include <iterator>

#include "hash.hpp"

ChainHashmap::HashFunc::HashFunc(size_t table_size)
    : m_index_count{table_size} {}

ChainHashmap::value_t ChainHashmap::HashFunc::operator()(value_t val) {
  return hash_multiplication(val, (std::sqrt(5) - 1) / 2, m_index_count);
  // return hash_division(val, 3);
}

ChainHashmap::ChainHashmap(size_t size) : m_chains(size), m_hash_func(size) {}

void ChainHashmap::insert(value_t val) {
  const auto hash = m_hash_func(val);
  chain_t &chain = *std::next(m_chains.begin(), hash);
  if (std::find(chain.cbegin(), chain.cend(), val) == chain.cend()) {
    chain.push_front(val);
  }
}

ChainHashmap::search_result_t ChainHashmap::search(value_t val) {
  const auto hash = m_hash_func(val);
  const chain_t &chain = *std::next(m_chains.begin(), hash);

  if (chain.empty()) {
    return search_result_t{false, 1};
  } else {
    const auto pos = std::find(chain.cbegin(), chain.cend(), val);
    return search_result_t{
        pos != chain.cend(),
        static_cast<size_t>(std::distance(chain.cbegin(), pos) + 1)};
  }
}
