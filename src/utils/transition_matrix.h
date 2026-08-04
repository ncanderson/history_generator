/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef TRANSITION_MATRIX_UTILS_H
#define TRANSITION_MATRIX_UTILS_H

#include <utils/dice_rolls.h>

namespace his_gen
{
/**
 * @brief Wrapper struct for defining the positive and negative
 * drivers in a given row of a state transition matrix.
 * @tparam E The enumeration to build the row out of
 */
template <typename E,
          typename = std::enable_if_t<std::is_enum_v<E>>>
struct Transition_drivers
{
  /**
   * @brief Enumerated values that will increase the probabilty
   * of a given enumeration being selected
   */
  std::vector<E> m_positive_drivers;

  /**
   * @brief Enumerated values that will decrease the probabilty
   * of a given enumeration being selected
   */
  std::vector<E> m_negative_drivers;

  /**
   * @brief Constructor
   * @param positive_drivers Vector of attributes
   * @param negative_drivers Vector of attributes
   */
  Transition_drivers(std::vector<E> positive_drivers,
                     std::vector<E> negative_drivers)
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
 * @brief Templated container class for working with transition matrices
 * @tparam E The enum type this instance will work with
 * @tparam A The attribute enum type this instance will work with
 */
template<typename E, typename A>
class Transition_matrix
{
  // This is very serious
  static_assert(std::is_enum_v<E>, "E must be an enum!");
  static_assert(std::is_enum_v<A>, "A must be an enum!");

public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Transition_matrix() = default;

  /**
   * @brief Destructor
   */
  ~Transition_matrix() = default;

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Enforcer of min/max values for the transition matrix rows
   */
  Bounds m_trans_matrix_bounds;

  /**
   * @brief A transition matrix built up for enum type E
   */
  dice::Transition_matrix<E> m_transition_matrix;

  // Implementation

};
}

#endif
