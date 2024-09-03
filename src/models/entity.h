/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_H
#define ENTITY_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>

namespace models
{
/**
 * @brief A generated entity
 */
class Entity
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Entity(std::string entity_name)
    :
      m_name(entity_name)
  {
    // NOOP
  }

  /**
   * @brief Destructor
   */
  ~Entity() {};

  /**
   * @brief Write entity object to JSON
   * @param json Pointer to the json we'll be writing to
   * @param entity The entity to write
   */
  void To_json(nlohmann::json& json,
               std::shared_ptr<Entity> entity);

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Entity name
   */
  std::string m_name;

  // Implementation

}; // class Entity
}  // namespace models

#endif // ENTITY_H
