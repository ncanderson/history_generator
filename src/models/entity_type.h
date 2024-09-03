/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_TYPE_H
#define ENTITY_TYPE_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>

namespace models
{
/**
 * @brief The type of entity
 */
class Entity_type
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Entity_type(){}

  /**
   * @brief Destructor
   */
  ~Entity_type() {};

  /**
   * @brief Write entity type object to JSON
   * @param json Pointer to the json we'll be writing to
   * @param entity_type The entity type to write
   */
  void To_json(nlohmann::json& json,
               std::shared_ptr<Entity_type> entity_type);

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Entity_type
}  // namespace models

#endif // ENTITY_TYPE_H
