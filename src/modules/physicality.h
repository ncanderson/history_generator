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
class Physicality : public Entity_attributes_base<Physicality, his_gen::Attribute_enums::EPhysicality>
{
  // This allows the base class to call the derived construct_attributes()
  friend class Entity_attributes_base<Physicality, Attribute_enums::EPhysicality>;

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
   * Getters and setters
   */
  const Repro_attribute_map& Get_repro_attributes() const { return m_repro_attributes; }
  bool Get_repro_attribute_value(const Attribute_enums::EReproduction repro_attribute) const;
  void Set_repro_attribute_value(const Attribute_enums::EReproduction repro_attribute,
                                 const bool value);

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
   * @brief Can_nurse_young
   * @return
   */
  bool Can_nurse_young();

  /**
   * @brief Update any attributes that are dependent on an instance's
   * reproductive abilities.
   * @details construct_attributes() will initialize the base class data
   * member, but won't have acccess to instance-specific attributes. This
   * function will fill out the missing attributes for a given instance
   * of this class. This function expects the base class member m_attributes
   * to be initialized.
   */
  void Update_repro_dependent_attributes();

protected:
  // Attributes
  /**
   * @brief Reproductive attributes of this entity
   */
  Repro_attribute_map m_repro_attributes;

  // Implementation
  /**
   * @brief Construct attributes for this personality
   */
  static Physical_attribute_map construct_attributes();

private:
  // Attributes

  // Implementation
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
