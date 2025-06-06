/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef RELATIONSHIP_TYPE_H
#define RELATIONSHIP_TYPE_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>

namespace his_gen
{
/**
 * @brief The type of relationship between entities
 */
class Relationship_type
{
public:
  // Attributes
  /**
   * @brief Relationship type name
   */
  std::string Name;

  // Implementation
  /**
   * @brief Default constructor, required for JSON serialization
   */
  Relationship_type() = default;

  /**
   * @brief Destructor
   */
  ~Relationship_type(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Relationship_type

void to_json(nlohmann::json& json,
             const his_gen::Relationship_type& relationship_type);

void from_json(const nlohmann::json& json,
               his_gen::Relationship_type& relationship_type);

}  // namespace his_gen

#endif // RELATIONSHIP_TYPE_H
