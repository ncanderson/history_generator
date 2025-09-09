/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DICE_ROLLS_H
#define DICE_ROLLS_H

// Standard libs
#include <stdint.h>
#include <stdexcept>
#include <random>
#include <map>

// JSON

// Application files

namespace his_gen
{
/**
 * @brief Utilities for random number generation
 */
namespace dice
{

/**
 * @brief Wrapper struct for defining the positive and negative
 * drivers in a given row of a state transition matrix.
 * @tparam Enum_t The enumeration to build the row out of
 */
template <typename Enum_t,
          typename = std::enable_if_t<std::is_enum_v<Enum_t>>>
struct Transition_drivers
{
  /**
   * @brief Enumerated values that will increase the probabilty
   * of a given enumeration being selected
   */
  std::vector<Enum_t> m_positive_drivers;

  /**
   * @brief Enumerated values that will decrease the probabilty
   * of a given enumeration being selected
   */
  std::vector<Enum_t> m_negative_drivers;

  /**
   * @brief Constructor
   * @param positive_drivers Vector of attributes
   * @param negative_drivers Vector of attributes
   */
  Transition_drivers(std::vector<Enum_t> positive_drivers,
                     std::vector<Enum_t> negative_drivers)
    :
    m_positive_drivers(positive_drivers),
    m_negative_drivers(negative_drivers)
  { }

}; // struct Transition_drivers

/**
 * @brief Templated using statement for building transition matrix patterns
 * @tparam Enum_key The enumeration to use when building the transition
 * matrix rows.
 * @tparam Enum_value The type of value container to use for positive and negative
 * drivers
 */
template <typename Enum_key, typename Enum_value>
using Transition_pattern = std::map<Enum_key, Transition_drivers<Enum_value>>;

/**
 * @brief Templated using statement for building transition matrices
 * @tparam Enum_key The enumeration to use when building the transition
 * matrix rows.
 */
template <typename Enum_key>
using Transition_matrix = std::map<Enum_key, std::map<Enum_key, double>>;

/**
 * @brief Singleton RNG generator accessor
 * @return The random generator
 */
std::mt19937& Get_generator();

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

  if constexpr(std::is_integral_v<T>)
  {
    std::uniform_int_distribution<T> dist(min_value, max_value);
    return dist(Get_generator());
  }
  else if constexpr(std::is_floating_point_v<T>)
  {
    std::uniform_real_distribution<T> dist(min_value, max_value);
    return dist(Get_generator());
  }
  else
  {
    static_assert(std::is_same_v<T, void>, "Unsupported numeric type");
  }
}

/**
   * @brief Make a weighted roll using a normal (Gaussian) distribution
   * @param mean Expected central value (should be between min and max)
   * @param stddev Standard deviation to control spread of values (higher = more spread)
   * @param min Minimum value allowed (inclusive)
   * @param max Maximum value allowed (inclusive)
   * @return A value distributed around mean with bell curve, clamped between min and max
   */
template<typename T>
T Make_weighted_roll(T max_value, T min_value, T mean = T(), T stddev = T())
{
  static_assert(std::is_floating_point_v<T>, "Make_weighted_roll requires floating point type");

  // If mean is not specified (default-constructed), use midpoint of min and max
  if (mean == T()) {
    mean = (min_value + max_value) / 2;
  }

  // If stddev is not specified, use 1/6th of the range (roughly 99.7% within range)
  if (stddev == T()) {
    stddev = (max_value - min_value) / 6;
  }

  std::normal_distribution<T> dist(mean, stddev);
  T roll = dist(Get_generator());

  // Clamp to [min, max]
  if (roll < min_value) roll = min_value;
  if (roll > max_value) roll = max_value;

  return roll;
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
  // Define the range
  std::uniform_int_distribution<size_t> dist(0, vector.size() - 1);
  // Get the object
  return std::forward<V>(vector)[dist(Get_generator())];
}

} // namespace dice
} // namespace his_gen

#endif // DICE_ROLLS_H
