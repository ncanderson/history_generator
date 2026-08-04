/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef TRANSITION_MATRIX_UTILS_H
#define TRANSITION_MATRIX_UTILS_H

#include <modules/personality.h>
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
 * @tparam Pattern The pattern this matrix will use
 */
template<typename Enum_key, typename Pattern>
class Transition_matrix
{
  // Enforce the usage of this templated class
  static_assert(std::is_enum_v<Enum_key>, "Enum_key must be an enum!");

  static_assert(std::is_same_v<Enum_key, typename Pattern::key_type>,
                "Enum_key must match the key type of Pattern!");

public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Transition_matrix()
    :
    m_trans_matrix_bounds(1,0)
  { }

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

  // Implementation
  /**
   * @brief Define a transition matrix using a Personality
   * @param entity_personality The personality of this entity which will determine
   * the probabilities in the transition matrix
   */
  void define_transition_matrix(const Pattern& transition_pattern,
                                const Personality& entity_personality)
  {
    // Iterate over relationship transition map, and discard the values (for now);
    // this will act on each possible next relationship
    for(const auto& [current_state, _] : transition_pattern)
    {
      // Running total of a row's weights
      double row_sum = 0.0;

      // Temporary map to hold unnormalized weights
      std::map<Enum_key, double> weights;

      // Inner loop to build the full matrix for the 'current_state', indicating
      // the likelihood of transition to the next state. This will use the 'drivers',
      // or the entity attributes that affect the chance of a next relationship.
      for(const auto& [next_state, drivers] : transition_pattern)
      {
        // base weight, the baseline chance for this relationship
        // TODO Set this in defs somewhere?
        double weight = 1.0;

        // Add positive influence, checking the entity for all personality traits
        // relevant to this relationship
        for (auto attr : drivers.m_positive_drivers)
        {
          weight += static_cast<double>(entity_personality.Get_entity_attribute_value(attr)) / 100.0;
        }

        // Subtract negative influence, checking the entity for all personality traits
        // relevant to this relationship
        for (auto attr : drivers.m_negative_drivers)
        {
          weight -= static_cast<double>(entity_personality.Get_entity_attribute_value(attr)) / 100.0;
        }

        // Enforce bounds
        m_trans_matrix_bounds.Enforce(weight);

        // Cache the fully calculated weights
        weights[next_state] = weight;

        // Get the running total of all weights
        row_sum += weight;
      }

      // Normalize the row so the full row will add up to 100%
      for (auto& [next_state, weight] : weights)
      {
        m_relationship_transition_matrix[current_state][next_state] = weight / row_sum;
      }
    }
  }

};
}

#endif
