/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef PERSONALITY_H
#define PERSONALITY_H

// Standard libs

// JSON
#include <deps/json.hpp>

// Application files

namespace his_gen
{
/**
 * @brief
 */
class Personality
{
public:
  // Attributes

  // Implementation
  /**
   * @brief
   * @param
   */
  Personality();

  /**
   * @brief Destructor
   */
  ~Personality(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief The Attribute enum
   * @details Containing pairs of opposed personality attributes, this enum
   * will be used as the key for a given entity's personality map. Use the
   * Get_attribute_string function when outputing these attributes to the data
   * storage.
   */
  enum Attribute
  {
    ATTRIBUTE_Aggressive_passive,
    ATTRIBUTE_Ambitious_lazy,
    ATTRIBUTE_Avoidant_sociable,
    ATTRIBUTE_Brave_cowardly,
    ATTRIBUTE_Cooperative_difficult,
    ATTRIBUTE_Cruel_kind,
    ATTRIBUTE_Decisive_indecisive,
    ATTRIBUTE_Diligent_lazy,
    ATTRIBUTE_Flexible_extremist,
    ATTRIBUTE_Frank_evasive,
    ATTRIBUTE_Generous_selfish,
    ATTRIBUTE_Helpful_useless,
    ATTRIBUTE_Jealous_compassionate,
    ATTRIBUTE_Placid_excitable,
    ATTRIBUTE_Thoughtful_rash,
    ATTRIBUTE_Thrifty_extravagant,
    ATTRIBUTE_Truculent_amiable,
    ATTRIBUTE_Witty_humorless
  };

  /**
   * @brief All personality attributes with corresponding values
   */
  std::map<Attribute, int8_t> m_personality_attributes;

  /**
   * @brief attracted_to_can_sire
   */
  bool attracted_to_can_sire;

  /**
   * @brief attracted_to_can_bear
   */
  bool attracted_to_can_bear;

  // Implementation
  /**
   * @brief Get the string representation of a personality attribute
   * @param attribute The attribute to get the string for.
   */
  std::string get_attribute_string(const Attribute attribute);

}; // class Personality

/**
 * @brief to_json
 * @param json
 * @param personality
 */
void to_json(nlohmann::json& json, const his_gen::Personality& personality);

/**
 * @brief from_json
 * @param json
 * @param personality
 */
void from_json(const nlohmann::json& json, his_gen::Personality& personality);

}  // namespace his_gen

#endif // PERSONALITY_H
