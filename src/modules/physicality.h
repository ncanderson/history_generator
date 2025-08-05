/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef PHYSICALITY_H
#define PHYSICALITY_H

// Standard libs
#include <string>
#include <variant>
#include <map>
#include <stdexcept>

// JSON
#include <deps/json.hpp>

// Application files
#include <defs/history_generator_defs.h>

namespace his_gen
{
/**
 * @brief Physical attributes for an entity with a body
 */
class Physicality
{

  enum class Physical_attributes : uint8_t
  {

  };


  /**
   * @brief The Unit enum, for specifying the value of a given
   * physical attribute.
   */
  enum class Unit : uint8_t
  {
    UNIT_Boolean, ///< A boolean
    UNIT_Scalar   ///< A scalar (ie numeric) value
  };

  using Physical_attr = std::variant<bool, double>;

}; // class Physicality
}  // namespace his_gen

#endif // PHYSICALITY_H
