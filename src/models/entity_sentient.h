/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_SENTIENT_H
#define ENTITY_SENTIENT_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <models/entity_base.h>
#include <utils/history_generator_utils.h>
#include <modules/personality.h>

namespace his_gen
{
/**
 * @brief A generated entity
 */
class Entity_sentient : public Entity_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Entity_sentient(std::string name, std::string title, bool test = true);

  /**
   * @brief Destructor
   */
  ~Entity_sentient(){};

  /**
   * @brief Get_personality
   * @return
   */
  Personality Get_personality() const { return m_personality; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Get this entity's personality
   */
  Personality m_personality;

  // Implementation

}; // class Entity

/**
 * @brief to_json
 * @param json
 * @param entity
 */
void to_json(nlohmann::json& json,
             const his_gen::Entity_sentient& entity_sentient);

/**
 * @brief from_json
 * @param json
 * @param entity
 */
void from_json(const nlohmann::json& json,
               his_gen::Entity_sentient& entity_sentient);

}  // namespace his_gen

#endif // ENTITY_SENTIENT_H
