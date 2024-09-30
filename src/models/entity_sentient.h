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
#include <modules/personality_attraction.h>

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
  Entity_sentient(std::string name,
                  std::string title,
                  bool full_random_reproduction= false);

  /**
   * @brief Destructor
   */
  ~Entity_sentient(){};

  /**
   * Getters and Setters
   */
  Personality Get_personality() const { return m_personality; }
  void Set_personality(Personality personality) { m_personality = personality; }

  bool Get_can_sire() const { return m_can_sire_young; }
  void Set_can_sire(bool can_sire_young) { m_can_sire_young = can_sire_young; }

  bool Get_can_bear() const { return m_can_bear_young; }
  void Set_can_bear(bool can_bear_young) { m_can_bear_young = can_bear_young; }


protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief This entity's personality
   */
  Personality m_personality;

  /**
   * @brief This entity's attraction
   */
  Personality_attraction m_personality_attraction;

  /**
   * @brief Entity can sire young
   */
  bool m_can_sire_young;

  /**
   * @brief Entity can bear young
   */
  bool m_can_bear_young;

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
