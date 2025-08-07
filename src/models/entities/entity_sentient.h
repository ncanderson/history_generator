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
#include <models/entities/entity_base.h>
#include <utils/history_generator_utils.h>
#include <modules/personality.h>
#include <modules/personality_attraction.h>
#include <modules/physicality.h>
#include <modules/physicality_attraction.h>

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
   * @param name
   * @param title
   * @param entity_type
   * @param full_random_reproduction
   */
  Entity_sentient(std::string name,
                  std::string title,
                  EEntity_type entity_type);

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
   * @brief Calling object Is_attracted to other_entity
   * @details `attracted_to` will be populated with `other_entity` if there
   * is attraction. This function does not handle mutual attraction, but expects
   * the caller to utilize the `attracted_to` vector populated here to make that
   * determination.
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
  void Set_personality(const Personality& personality) { m_personality = personality; }

  Personality_attraction Get_personality_attraction() const { return m_personality_attraction; }
  void Set_personality_attraction(const Personality_attraction& personality_attraction) { m_personality_attraction = personality_attraction; }

  Physicality Get_physicality() const { return m_physicality; }
  void Set_physicality(const Physicality& physicality) { m_physicality = physicality; }

  Physicality_attraction Get_physicality_attraction() const { return m_physicality_attraction; }
  void Set_physicality_attraction(const Physicality_attraction& physicality_attraction) { m_physicality_attraction = physicality_attraction; }

  std::vector<std::shared_ptr<his_gen::Entity_base>> Get_spouses() const { return m_spouses; }
  void Set_spouses(const std::vector<std::shared_ptr<his_gen::Entity_base>>& spouses) { m_spouses = spouses; }
  void Add_spouse(const std::shared_ptr<his_gen::Entity_base>& spouse) { m_spouses.push_back(spouse); }

  std::vector<std::shared_ptr<his_gen::Entity_base>> Get_lovers() const { return m_lovers; }
  void Set_lovers(const std::vector<std::shared_ptr<his_gen::Entity_base>>& lovers) { m_lovers = lovers; }
  void Add_lover(const std::shared_ptr<his_gen::Entity_base>& lover) { m_lovers.push_back(lover); }

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
   * @brief This entity's personality attraction threshold, or the number
   * of compatible personality attributes this entity looks for when
   * determining attraction.
   */
  uint8_t m_personality_attraction_thresh;

  /**
   * @brief This entity's physical appearence
   */
  Physicality m_physicality;

  /**
   * @brief This entity's attraction to the physical appearence of others
   */
  Physicality_attraction m_physicality_attraction;

  /**
   * @brief This entity's physical attraction threshold, or the number
   * of compatible physical attributes this entity looks for when
   * determining attraction.
   */
  uint8_t m_physicality_attraction_thresh;

  /**
   * @brief m_spouses Spouses of this entity
   */
  std::vector<std::shared_ptr<his_gen::Entity_base>> m_spouses;

  /**
   * @brief Lovers of this entity (but not spouses)
   */
  std::vector<std::shared_ptr<his_gen::Entity_base>> m_lovers;

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

  /**
   * @brief Calculate the number of compatible personality attributes this entity
   * requires to be attracted to another entity.
   * @return The attraction threshold.
   */
  uint8_t derive_personality_attraction_thresh();

  /**
   * @brief Loop through all personality attributes for this and other_entity and compare each attribute.
   * @details This function will utilize this entity's personality attraction flexibility
   * to determine the minimum number of compatible attributes required for attraction.
   * @param other_entity The entity to compare to.
   * @return True if the number of compatible attributes is greater than or equal to this
   * entity's attraction flexibility.
   */
  bool compare_personalities(std::shared_ptr<his_gen::Entity_sentient> other_entity);

  /**
   * @brief Check compatibility of personality attraction.
   * @details Subtract the argued entity attribute from the attraction attribute,
   * take the absolute value, and compare it to the attraction flexibility.
   * This will return false if any compared attribute doesn't meet the
   * flexibility requirements.
   * @param other_entity Other entity to compare to
   * @param pers_attr_to_compare The attribute to check
   * @return True if the difference between these attributes is within this entity's
   * flexibility range, otherwise false.
   */
  bool personality_attributes_compatible(std::shared_ptr<his_gen::Entity_sentient> other_entity,
                                         Personality::Personality_attribute pers_attr_to_compare);

  /**
   * @brief Calculate the number of compatible physicality attributes this entity
   * requires to be attracted to another entity.
   * @return The attraction threshold.
   */
  uint8_t derive_physicality_attraction_thresh();

  /**
   * @brief Loop through all physical attributes for this and other_entity and compare each attribute.
   * @details This function will utilize this entity's physical attraction flexibility
   * to determine the minimum number of compatible attributes required for attraction.
   * @param other_entity The entity to compare to.
   * @return True if the number of compatible attributes is greater than or equal to this
   * entity's attraction flexibility.
   */
  bool compare_physicalities(std::shared_ptr<his_gen::Entity_sentient> other_entity);

  /**
   * @brief Check compatibility of physicality attraction.
   * @details Subtract the argued entity attribute from the attraction attribute,
   * take the absolute value, and compare it to the attraction flexibility.
   * This will return false if any compared attribute doesn't meet the
   * flexibility requirements.
   * @param other_entity Other entity to compare to
   * @param phys_attr_to_compare The attribute to check
   * @return True if the difference between these attributes is within this entity's
   * flexibility range, otherwise false.
   */
  bool physicality_attributes_compatible(std::shared_ptr<his_gen::Entity_sentient> other_entity,
                                         Physicality::Physical_attribute phys_attr_to_compare);

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
