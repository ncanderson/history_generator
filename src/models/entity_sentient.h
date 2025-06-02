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
class Entity_sentient : public Entity_base,
                        public std::enable_shared_from_this<Entity_sentient>
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
   * @brief Check if this entity is attracted to `other_entity`
   * @param other_entity The entity to check
   * @return True if `this` is attracted to `other_entity`, otherwise false.
   */
  bool Is_attracted(std::shared_ptr<Entity_base> other_entity) override;

  /**
   * @brief Is_attracted to other_entity
   * @details `attracted_to` will only be populated with `other_entity` if there
   * is attraction. This function does not handle mutual attraction, but expects
   * the caller to utilize the `attracted_to` vector populated here.
   * @param other_entity The entity to compare to
   * @param attracted_to Vector to populate with attraction partners
   * @return True if `this` is attracted to `other_entity`, otherwise false.
   */
  bool Is_attracted(std::shared_ptr<Entity_base> other_entity,
                    std::vector<std::shared_ptr<Entity_base>> attracted_to) override;

  /**
   * Getters and Setters
   */
  Personality Get_personality() const { return m_personality; }
  void Set_personality(Personality personality) { m_personality = personality; }

  Personality_attraction Get_personality_attraction() const { return m_personality_attraction; }
  void Set_personality_attraction (Personality_attraction personality_attraction) { m_personality_attraction = personality_attraction; }

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
  /**
   * @brief Check the reproductive attraction of this compared to some other
   * entity.
   * @details This function evaulates attraction to reproduction exclusively,
   * and will not consider any other attributes of a sentient entity, like gender,
   * sexuality, mutual attraction, etc.
   * @param other_entity The entity to evaulate against this
   * @return True if attraced, otherwise false
   */
  bool repro_attraction(std::shared_ptr<his_gen::Entity_sentient> other_entity);

}; // class Entity_sentient

/**
 * @brief to_json
 * @param json
 * @param entity_sentient
 */
void to_json(nlohmann::json& json,
             const his_gen::Entity_sentient& entity_sentient);

/**
 * @brief from_json
 * @param json
 * @param entity_sentient
 */
void from_json(const nlohmann::json& json,
               his_gen::Entity_sentient& entity_sentient);

}  // namespace his_gen

#endif // ENTITY_SENTIENT_H
