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
#include <models/relationships/relationship_type.h>
#include <modules/personality.h>
#include <modules/personality_attraction.h>
#include <modules/physicality.h>
#include <modules/physicality_attraction.h>
#include <utils/dice_rolls.h>
#include <utils/history_generator_utils.h>

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
   * @brief Constructor allowing the utilization of static name/title retrieval
   * @param entity_type The type of entity to instantiate.
   * @param current_tick The current generation tick
   */
  Entity_sentient(const EEntity_type entity_type,
                  const uint64_t current_tick);

  /**
   * @brief Overloaded constructor if an externally-specified name
   * and title are desired
   * @param name
   * @param title
   * @param entity_type
   * @param current_tick
   */
  Entity_sentient(const std::string& name,
                  const std::string& title,
                  const EEntity_type entity_type,
                  const uint64_t current_tick);

  /**
   * @brief Destructor
   */
  ~Entity_sentient(){};

  /**
   * @brief Initialize this class's attributes
   */
  void Initialize() override;

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

protected:
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
   * @brief This entity's personality attraction threshold, used to determine
   * compability, based on personal flexibility
   */
  double m_personality_attraction_thresh;

  /**
   * @brief This entity's physical appearence
   */
  Physicality m_physicality;

  /**
   * @brief This entity's attraction to the physical appearence of others
   */
  Physicality_attraction m_physicality_attraction;

  /**
   * @brief This entity's physicality attraction threshold, used to determine
   * compability, based on personal flexibility
   */
  double m_physicality_attraction_thresh;

  /**
   * @brief How likely this entity is to take a risk on more divergent attributes
   */
  double m_attraction_risk_appetite;

  // Implementation

private:
  // Attributes

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
  virtual bool repro_attraction(std::shared_ptr<his_gen::Entity_sentient> other_entity);

  /**
   * @brief Calculate the compatibility threshold for this entity
   * @param entity_flexibility The entity's flexibility
   * @return The attraction threshold.
   */
  double derive_attraction_thresh(uint8_t entity_flexibility);

  /**
   * @brief Loop through all attributes for this and other_entity and compare each attribute.
   * @details This function will utilize this entity's attraction flexibility to determine
   * the minimum number compatibility required.
   * @param other_entity The entity to compare to.
   * @return True if the number of compatible attributes is greater than or equal to this
   * entity's attraction flexibility.
   */
  template <typename Attribute_class>
  bool compare_attributes(const Attribute_class& self_attribute_class,
                          const Attribute_class& other_attribute_class)
  {
    double total_difference = 0.0;
    for (auto& it : self_attribute_class.Get_attributes())
    {
      total_difference += entity_attribute_diff(self_attribute_class,
                                                other_attribute_class,
                                                it.first);
    }

    double entity_similarity = 1.0 - (total_difference / self_attribute_class.Get_max_attribute_diff());
    double attraction_chance = entity_similarity * get_attraction_threshold<Attribute_class>();
    // This declare separately to help with debugging
    double weighted_roll = his_gen::dice::Make_weighted_roll<double>(1,
                                                                     0,
                                                                     attraction_chance,
                                                                     m_attraction_risk_appetite);
    return weighted_roll < attraction_chance;
  }

  /**
   * @brief Get the difference betwees personality attributes and attraction.
   * @param other_entity Other entity to compare to
   * @param pers_attr_to_compare The attribute to check
   * @return The absolute difference between the two atributes
   */
  template <typename Enum_type, typename Container_type>
  uint8_t entity_attribute_diff(const Container_type& self_container,
                                const Container_type& other_container,
                                Enum_type attr_to_compare)
  {
    uint8_t self_attr  = self_container.Get_entity_attribute_value(attr_to_compare);
    uint8_t other_attr = other_container.Get_entity_attribute_value(attr_to_compare);
    return static_cast<uint8_t>(std::fabs(self_attr - other_attr));
  }

  /**
   * @brief Get_attraction_threshold
   * @tparam T The attribute class to get the threshold for
   * @return The correct threshold based on the attribute class being used
   */
  template<typename T>
  double get_attraction_threshold() const
  {
    if constexpr (std::is_same_v<T, Physicality>)
      return m_physicality_attraction_thresh;
    else if constexpr (std::is_same_v<T, Personality>)
      return m_personality_attraction_thresh;
    else
      static_assert(std::is_same_v<T, void>, "Unsupported attribute class type");
  }

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
