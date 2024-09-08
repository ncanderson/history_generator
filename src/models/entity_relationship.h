/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_RELATIONSHIP_H
#define ENTITY_RELATIONSHIP_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>

namespace his_gen
{
/**
 * @brief The relationship between two entities
 */
class Entity_relationship
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Entity_relationship(){}

  /**
   * @brief Destructor
   */
  ~Entity_relationship() {};

  /**
   * @brief Write entity relationship object to JSON
   * @param json Pointer to the json we'll be writing to
   * @param entity_relationship The entity relationship to write
   */
  void To_json(nlohmann::json& json,
               std::shared_ptr<Entity_relationship> entity_relationship);

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Entity_relationship

void to_json(nlohmann::json& json,
             const his_gen::Entity_relationship& entity_relationship);

void from_json(const nlohmann::json& json,
               his_gen::Entity_relationship& entity_relationship);

}  // namespace his_gen

#endif // ENTITY_RELATIONSHIP_H
