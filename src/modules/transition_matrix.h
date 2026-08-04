/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef TRANSITION_MATRIX_UTILS_H
#define TRANSITION_MATRIX_UTILS_H

#include <optional>

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
  using Matrix_row = std::map<Enum_key, double>;
  using Matrix = std::map<Enum_key, Matrix_row>;

  // Implementation
  /**
   * @brief Constructor
   */
  Transition_matrix()
    :
    m_trans_matrix_bounds(1, 0)
  { }

  /**
   * @brief Destructor
   */
  ~Transition_matrix() = default;

  /**
   * @brief Define a transition matrix using a Personality
   * @details To support the usage of this function, a Personality is accessible through
   * Entity_base. However, because not all children of Entity_base will have a personality,
   * the default `Get_personality()` will return a `nullptr` in Event_base. An assertion
   * is used here to ensure this function is only used for a valid Personality, ensuring
   * that any invalid uses are flagged during development.
   * @param Pattern The pattern for the transition matrix, which will contain the
   * positive and negative personality drivers for the transitions
   * @param entity_personality The personality of this entity which will determine
   * the probabilities in the transition matrix
   */
  void Define_transition_matrix(const Pattern& transition_pattern,
                                const Personality* entity_personality)
  {
    // Guard against improper usage
    assert(entity_personality != nullptr &&
           "Define_transition_matrix requires a Personality!");

    // Iterate over the transition pattern, and discard the values (for now);
    // this will act on each possible next Enum_key in the transition matrix
    for(const auto& [current_state, _] : transition_pattern)
    {
      // Running total of a row's weights
      double row_sum = 0.0;

      // Temporary map to hold unnormalized weights
      std::map<Enum_key, double> weights;

      // Inner loop to build the full matrix for the 'current_state', indicating
      // the likelihood of transition to the next state. This will use the 'drivers',
      // or the entity attributes that affect the chance of a next state.
      for(const auto& [next_state, drivers] : transition_pattern)
      {
        // base weight, the baseline chance for this transition
        // TODO Set this in defs somewhere?
        double weight = 1.0;

        // Add positive influence, checking the entity for all relevant personality traits
        for (auto attr : drivers.m_positive_drivers)
        {
          weight += static_cast<double>(entity_personality->Get_entity_attribute_value(attr)) / 100.0;
        }

        // Subtract negative influence, checking the entity for all relevant personality traits
        for (auto attr : drivers.m_negative_drivers)
        {
          weight -= static_cast<double>(entity_personality->Get_entity_attribute_value(attr)) / 100.0;
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
        m_transition_matrix[current_state][next_state] = weight / row_sum;
      }
    }
  }

  /**
   * @brief Get a matrix row by Enum_key
   * @param enum_key The Enum_key to get the row of
   * @return The matrix row corresponding to enum_key
   * @throws std::runtime_error Thrown if the requested row is not present
   */
  const std::map<Enum_key, double>& Get_matrix_row(Enum_key enum_key) const
  {
    const auto row_it = m_transition_matrix.find(enum_key);

    // Throw if the row is empty
    if(row_it == m_transition_matrix.end())
    {
      throw std::runtime_error("No transition data for requested enum value");
    }

    return row_it->second;
  }

  /**
   * @brief Rolls for a transition from the supplied current type.
   * @return The selected next type, or std::nullopt when the roll does
   * not fall within the cumulative transition probabilities.
   * @throws std::out_of_range Thrown if enum_key has no matrix row
   */
  std::optional<Enum_key> Roll_transition(Enum_key enum_key) const
  {
    // Throws std::out_of_range if the expected row is missing.
    const Matrix_row& transitions = m_transition_matrix.at(enum_key);

    const double roll = his_gen::dice::Make_a_roll<double>(1.0, 0.0);

    double cumulative_probability = 0.0;

    for(const auto& [next_type, probability] : transitions)
    {
      cumulative_probability += probability;

      if(roll <= cumulative_probability)
      {
        return next_type;
      }
    }

    // Made it here? The row's probabilities totaled less than the generated roll;
    // this represents no transition
    return std::nullopt;
  }

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
   * @brief The point of all this; the actual matrix to be constructed by this
   * templated wrapper
   */
  std::map<Enum_key, std::map<Enum_key, double>> m_transition_matrix;

};
}

#endif
