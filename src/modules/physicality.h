/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef PHYSICALITY_H
#define PHYSICALITY_H

// Standard libs
#include <map>

// JSON
#include <deps/json.hpp>

// Application files
#include <modules/entity_attributes_base.h>
#include <defs/history_generator_defs.h>

namespace his_gen
{
/**
 * @brief Physical attributes for an entity with a body
 */
class Physicality : public Entity_attributes_base<his_gen::Attribute_enums::EPhysicality>
{
public:

  /**
   * @brief Physicality constructor
   */
  Physicality();

  /**
   * @brief Destructor
   */
  ~Physicality() = default;

  /**
   * Usings
   */
  using Physical_attribute_map = std::map<Attribute_enums::EPhysicality, uint8_t>;
  using Repro_attribute_map = std::map<Attribute_enums::EReproduction, bool>;

  /**
   * Overrides
   */
  Physical_attribute_map Get_attributes() const override { return m_physical_attributes; }

  /**
   * @brief Get a physical attribute from this class
   * @param attribute The enumerated attribute to get
   * @return The value of this attribute
   */
  uint8_t Get_entity_attribute_value(const Attribute_enums::EPhysicality attribute) const override;

  /**
   * Other public functions
   */

  /**
   * @brief Get a repro attribute from this class
   * @param attribute The enumerated attribute to get
   * @return The value of this attribute
   */
  bool Get_repro_attribute_value(const Attribute_enums::EReproduction repro_attribute) const;

  /**
   * @brief Can_bear_young
   * @return
   */
  bool Can_bear_young();

  /**
   * @brief Can_sire_young
   * @return
   */
  bool Can_sire_young();

  /**
   * Getters and setters
   */
  Repro_attribute_map Get_repro_attributes() const { return m_repro_attributes; }

  uint8_t Get_number_of_attributes() const { return m_num_attributes; }
  uint16_t Get_max_attribute_diff() const { return m_max_attribute_diff; }

protected:
  // Attributes
  /**
   * @brief Reproductive attributes of this entity
   */
  Repro_attribute_map m_repro_attributes;

  /**
   * @brief The attributes and values for this entity
   */
  Physical_attribute_map m_physical_attributes;

  // Implementation

private:
  // Attributes
  // TODO: Make this a static value since it won't change at runtime
  /**
   * @brief The number of attributes
   */
  uint8_t m_num_attributes;

  // TODO: Make this a static value since it won't change at runtime
  /**
   * @brief The maximum possible difference across all attributes
   */
  uint16_t m_max_attribute_diff;

  // Implementation
  // TODO: Move to the base class (along with personality attr construct)
  /**
   * @brief construct_physicality_attributes
   * @return
   */
  Physical_attribute_map construct_physicality_attributes();

  /**
   * @brief construct_repro_attributes
   * @return
   */
  Repro_attribute_map construct_repro_attributes();

}; // class Physicality

/**
 * @brief to_json
 * @param json
 * @param physicality
 */
void to_json(nlohmann::json& json,
             const his_gen::Physicality& physicality);

/**
 * @brief from_json
 * @param json
 * @param physicality
 */
void from_json(const nlohmann::json& json,
               his_gen::Physicality& physicality);

}  // namespace his_gen

#endif // PHYSICALITY_H
