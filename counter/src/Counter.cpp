#include "Counter.hpp"

#include <algorithm>
#include <array>
#include <cstddef>
#include <sys/types.h>

#include "hash.hpp"
#include "hash_division.hpp"
#include "hash_multiplication.hpp"
#include "hash_square_center.hpp"
#include "hash_wrapping.hpp"

Counter::Counter(size_t size) : m_rgen(rdev()) {}

Counter::collision_count_t Counter::calc_collisions(key_t (*hash_func)(key_t)) {
  collision_count_t result{0};
  rand_distrib_t dist(rand_min, rand_max);

  hash_table_t table(table_size);
  for (batch_size_t i{0}; i < batch_size; ++i) {
    key_t key = dist(m_rgen);
    key_t hash = hash_func(key);
    hash_chain_t &chain = table.at(hash);
    if (chain.empty()) {
      chain.push_front(key);
    } else {
      if (std::find(chain.cbegin(), chain.cend(), key) == chain.cend()) {
        ++result;
      }
    }
  }

  return result;
}

Counter::full_collision_count_t Counter::calc_collisions() {
  m_rgen.seed(rdev());

  const auto div = [](key_t key) { return hash_division(key, 997); };
  const auto mult = [](key_t key) {
    return hash_multiplication(key, (std::sqrt(5) - 1) / 2, table_size);
  };
  const auto square = [](key_t key) { return hash_midsquare(key, 3); };
  const auto wrap = [](key_t key) { return hash_wrapping(key, table_size); };

  full_collision_count_t result{calc_collisions(div), calc_collisions(mult),
                                calc_collisions(square), calc_collisions(wrap)};

  return result;
}

void Counter::calc_score(batch_count_t batches) {
  m_scores = {0, 0, 0, 0};
  for (batch_count_t i{0}; i < batches; ++i) {
    full_collision_count_t collisions = calc_collisions();

    const std::array<collision_count_t, 4> collisions_array{
        collisions.division, collisions.multiplication, collisions.midsquare,
        collisions.wrapping};

    collision_count_t min_collisions =
        *std::min(collisions_array.cbegin(), collisions_array.cend());

    m_scores.division += ((collisions.division <= min_collisions) ? 1 : 0);
    m_scores.multiplication +=
        ((collisions.multiplication <= min_collisions) ? 1 : 0);
    m_scores.midsquare += ((collisions.midsquare <= min_collisions) ? 1 : 0);
    m_scores.wrapping += ((collisions.wrapping <= min_collisions) ? 1 : 0);
  }
}

Counter::full_score_t Counter::score() const { return m_scores; }
