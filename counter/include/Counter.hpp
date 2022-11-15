#pragma once

#include <cstddef>
#include <cstdint>
#include <forward_list>
#include <random>
#include <vector>

class Counter final {
public:
  using key_t = std::uint64_t;
  using collision_count_t = std::size_t;
  using score_t = std::size_t;
  using batch_count_t = std::size_t;
  using batch_size_t = std::size_t;
  using table_size_t = std::size_t;

  using full_collision_count_t = struct FullCollisionCount {
    collision_count_t division;
    collision_count_t multiplication;
    collision_count_t midsquare;
    collision_count_t wrapping;
  };

  using full_score_t = struct FullScore {
    score_t division;
    score_t multiplication;
    score_t midsquare;
    score_t wrapping;
  };

  using hash_chain_t = std::forward_list<key_t>;
  using hash_table_t = std::vector<hash_chain_t>;

  using size_t = std::size_t;

  using rand_dev_t = std::random_device;
  using rand_gen_t = std::mt19937_64;
  using rand_distrib_t = std::uniform_int_distribution<key_t>;

public:
  Counter(size_t);

  void calc_score(batch_count_t);
  full_score_t score() const;

private:
  full_collision_count_t calc_collisions();
  collision_count_t calc_collisions(key_t (*)(key_t));

private:
  const static key_t rand_min{0};
  const static key_t rand_max{100'000};
  const static batch_size_t batch_size{1000};
  const static table_size_t table_size{1000};
  static rand_dev_t rdev;

  rand_gen_t m_rgen;
  full_score_t m_scores;
};