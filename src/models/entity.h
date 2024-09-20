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

namespace his_gen
{
/**
 * @brief A generated entity
 */
class Entity
{
public:
  // Attributes
  /**
   * @brief Entity name
   */
  std::string Name;

  /**
   * @brief Entity title
   */
  std::string Title;

  // Implementation
  /**
   * @brief Constructor
   */
  Entity(std::string name, std::string title = "");

  /**
   * @brief Destructor
   */
  ~Entity(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Entity

/**
 * @brief to_json
 * @param json
 * @param entity
 */
void to_json(nlohmann::json& json, const his_gen::Entity& entity);

/**
 * @brief from_json
 * @param json
 * @param entity
 */
void from_json(const nlohmann::json& json, his_gen::Entity& entity);

}  // namespace his_gen

#endif // ENTITY_H
