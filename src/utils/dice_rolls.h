/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DICE_ROLLS_H
#define DICE_ROLLS_H

#include <stdint.h>
#include <stdexcept>
#include <random>

namespace his_gen
{
/**
 * @brief Utilities for random number generation
 */
namespace dice
{
/**
 * @brief Generate a random number between min and max
 * @param max_value
 * @param min_value
 * @return
 */
template<typename T>
T Make_a_roll(uint32_t max_value, uint32_t min_value = 1)
{
  static_assert(std::is_arithmetic_v<T>, "T must be numeric");

  // Initialize a random number generator
  std::random_device rand;
  std::mt19937 generate(rand());

  if constexpr(std::is_integral_v<T>)
  {
    std::uniform_int_distribution<T> dist(min_value, max_value);
    return dist(generate);
  }
  else if constexpr(std::is_floating_point_v<T>)
  {
    std::uniform_real_distribution<T> dist(min_value, max_value);
    return dist(generate);
  }
  else
  {
    static_assert(std::is_same_v<T, void>, "Unsupported numeric type");
  }
}

/**
 * @brief Little wrapper to make it clear when we want a boolean value
 * @return Returns a boolean derived from a 0 - 1 range random roll.
 */
bool Flip_a_coin();

/**
 * @brief Get a random element from a vector
 * @tparam V The vector definition
 * @param vector The vector to select from
 * @return The selected object, preserving value type
 */
template <typename V>
decltype(auto) Get_random_element(V&& vector)
{
  if (vector.empty())
  {
    throw std::out_of_range("Cannot get random element from empty vector");
  }

  // Set up the random seed
  static std::random_device rd;
  static std::mt19937 gen(rd());
  // Define the range
  std::uniform_int_distribution<size_t> dist(0, vector.size() - 1);
  // Get the object
  return std::forward<V>(vector)[dist(gen)];
}

} // namespace dice
} // namespace his_gen

#endif // DICE_ROLLS_H
