#include "OpenAddressHashmap.hpp"
#include "hash_division.hpp"
#include <cstddef>

OpenAddressHashmap::HashFunc::HashFunc(size_t table_size)
    : m_index_count{table_size} {}

OpenAddressHashmap::value_t
OpenAddressHashmap::HashFunc::operator()(value_t val) {
  return hash_multiplication(val, (std::sqrt(5) - 1) / 2, m_index_count);
  // return hash_division(val, 3);
}

OpenAddressHashmap::OpenAddressHashmap(size_t table_size)
    : m_hash_func(table_size), m_cells(table_size){};

void OpenAddressHashmap::insert(value_t val) {
  const auto hash = m_hash_func(val);
  const auto pos = std::next(m_cells.begin(), hash);

  const auto insert_func = [&val](cell_t &cell) {
    if (cell.free) {
      cell.value = val;
      cell.free = false;
      cell.search_skip = false;
      return true;
    }
    return false;
  };

  for (auto i{pos}; i != m_cells.end(); std::advance(i, 1)) {
    if (insert_func(*i)) {
      return;
    }
  }
  for (auto i{m_cells.begin()}; i != pos; std::advance(i, 1)) {
    if (insert_func(*i)) {
      return;
    }
  }
}

OpenAddressHashmap::search_result_t OpenAddressHashmap::search(value_t val) {
  const auto hash = m_hash_func(val);
  const auto pos = std::next(m_cells.begin(), hash);

  enum class SearchRes { NotFound, Found, Skip };
  const auto search_func = [&val](const cell_t &cell) {
    if (!cell.free) {
      if (cell.search_skip || (cell.value != val)) {
        return SearchRes::Skip;
      } else {
        return SearchRes::Found;
      }
    }
    return SearchRes::NotFound;
  };

  size_t comparisons{0};

  for (auto i{pos}; i != m_cells.end(); std::advance(i, 1)) {
    ++comparisons;
    switch (search_func(*i)) {
    case SearchRes::Skip:
      continue;
      break;
    case SearchRes::Found:
      return search_result_t{true, comparisons};
      break;
    case SearchRes::NotFound:
      return search_result_t{false, comparisons};
      break;
    }
  }
  for (auto i{m_cells.begin()}; i != pos; std::advance(i, 1)) {
    ++comparisons;
    switch (search_func(*i)) {
    case SearchRes::Skip:
      continue;
      break;
    case SearchRes::Found:
      return search_result_t{true, comparisons};
      break;
    case SearchRes::NotFound:
      return search_result_t{false, comparisons};
      break;
    }
  }
  return search_result_t{false, comparisons};
}