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

namespace models
{
/**
 * @brief Relationships allowed between two entities of a given type
 */
class Entity_type_relationship_type
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Entity_type_relationship_type(){}

  /**
   * @brief Destructor
   */
  ~Entity_type_relationship_type(){};

  /**
   * @brief Write entity relationship object to JSON
   * @param json Pointer to the json we'll be writing to
   * @param entity_relationship The entity relationship to write
   */
  void To_json(nlohmann::json& json,
               std::shared_ptr<Entity_type_relationship_type> entity_type_relationship_type);

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Entity_type_relationship_type
}  // namespace models

#endif // ENTITY_TYPE_RELATIONSHIP_TYPE_H
