/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_TYPE_H
#define ENTITY_TYPE_H

// Standard libs

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <defs/history_generator_defs.h>

namespace his_gen
{
/**
 * @brief The type of entity
 */
class  Entity_type
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Default constructor, required for JSON serialization
   */
  Entity_type() = default;

  /**
   * @brief Constructor
   */
  Entity_type(const his_gen::EEntity_type& entity_type);

  /**
   * @brief Destructor
   */
  ~Entity_type() = default;

  /**
   * Getters and setters
   */
  std::string Get_name() const { return m_name; }
  his_gen::EEntity_type Get_entity_type() const { return m_entity_type; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Entity type name
   */
  std::string m_name;

  /**
   * @brief Enumerated entity type
   */
  his_gen::EEntity_type m_entity_type;

  // Implementation

}; // class Entity_type

/**
 * @brief to_json
 * @param json
 * @param entity_type
 */
void to_json(nlohmann::json& json,
             const his_gen::Entity_type& entity_type);

/**
 * @brief from_json
 * @param json
 * @param entity_type
 */
void from_json(const nlohmann::json& json,
               his_gen::Entity_type& entity_type);

}  // namespace his_gen

#endif // ENTITY_TYPE_H
