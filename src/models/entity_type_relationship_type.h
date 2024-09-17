/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_TYPE_RELATIONSHIP_TYPE_H
#define ENTITY_TYPE_RELATIONSHIP_TYPE_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>

namespace his_gen
{
/**
 * @brief Relationships allowed between two entities of a given type
 */
class Entity_type_relationship_type
{
public:
  // Attributes
  /**
   * @brief Entity type for this relationship
   */
  std::string Entity_type;

  /**
   * @brief Relationship type for this relationship
   */
  std::string Relationship_type;

  // Implementation
  /**
   * @brief Constructor
   */
  Entity_type_relationship_type(){}

  /**
   * @brief Destructor
   */
  ~Entity_type_relationship_type(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Entity_type_relationship_type

void to_json(nlohmann::json& json,
             const his_gen::Entity_type_relationship_type& entity_type_relationship_type);

void from_json(const nlohmann::json& json,
               his_gen::Entity_type_relationship_type& entity_type_relationship_type);

}  // namespace his_gen

#endif // ENTITY_TYPE_RELATIONSHIP_TYPE_H
