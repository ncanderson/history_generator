/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef PERSONALITY_H
#define PERSONALITY_H

// Standard libs

// JSON
#include <deps/json.hpp>

// Application files
#include <defs/history_generator_defs.h>

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


  // TODO: figure out some way to keep the pairs aligned? Maybe use a key for the
  // enum member's values, or a separate structure that keeps them together in
  // pairs?
  // TODO: Move into the personality module
  /**
 * @brief The Attribute enum
 * @details Containing pairs of opposed personality attributes, this enum
 * will be used as the key for a given entity's personality map. Use the
 * Get_attribute_string function when outputing these attributes to the data
 * storage.
 */
  enum class Personality_attribute : uint8_t
  {
    PERSONALITY_ATTRIBUTE_Aggressive,
    PERSONALITY_ATTRIBUTE_Passive,
    PERSONALITY_ATTRIBUTE_Ambitious,
    PERSONALITY_ATTRIBUTE_Content,
    PERSONALITY_ATTRIBUTE_Avoidant,
    PERSONALITY_ATTRIBUTE_Sociable,
    PERSONALITY_ATTRIBUTE_Brave,
    PERSONALITY_ATTRIBUTE_Cowardly,
    PERSONALITY_ATTRIBUTE_Cooperative,
    PERSONALITY_ATTRIBUTE_Difficult,
    PERSONALITY_ATTRIBUTE_Cruel,
    PERSONALITY_ATTRIBUTE_Kind,
    PERSONALITY_ATTRIBUTE_Decisive,
    PERSONALITY_ATTRIBUTE_Indecisive,
    PERSONALITY_ATTRIBUTE_Diligent,
    PERSONALITY_ATTRIBUTE_Lazy,
    PERSONALITY_ATTRIBUTE_Flexible,
    PERSONALITY_ATTRIBUTE_Extremist,
    PERSONALITY_ATTRIBUTE_Frank,
    PERSONALITY_ATTRIBUTE_Evasive,
    PERSONALITY_ATTRIBUTE_Generous,
    PERSONALITY_ATTRIBUTE_Selfish,
    PERSONALITY_ATTRIBUTE_Jealous,
    PERSONALITY_ATTRIBUTE_Compassionate,
    PERSONALITY_ATTRIBUTE_Placid,
    PERSONALITY_ATTRIBUTE_Excitable,
    PERSONALITY_ATTRIBUTE_Thoughtful,
    PERSONALITY_ATTRIBUTE_Rash,
    PERSONALITY_ATTRIBUTE_Thrifty,
    PERSONALITY_ATTRIBUTE_Extravagant,
    PERSONALITY_ATTRIBUTE_Argumentative,
    PERSONALITY_ATTRIBUTE_Amiable,
    PERSONALITY_ATTRIBUTE_Witty,
    PERSONALITY_ATTRIBUTE_Humorless,
    PERSONALITY_ATTRIBUTE_Honest,
    PERSONALITY_ATTRIBUTE_Deceitful,
    PERSONALITY_ATTRIBUTE_Lustful,
    PERSONALITY_ATTRIBUTE_Chaste
  };

  /**
   * Usings
   */
  using Personality_attribute_map = std::map<Personality_attribute, uint8_t>;

  /**
   * @brief Get the string representation of a personality attribute
   * @param attribute The attribute to get the string for.
   */
  static std::string Get_attribute_string(const Personality_attribute attribute);

  /**
   * Getters and setters
   */
  std::map<Personality_attribute, int8_t> Get_attributes() const { return m_personality_attributes; }

protected:
  // Attributes
  /**
   * @brief All personality attributes with corresponding values
   */
  std::map<Personality_attribute, int8_t> m_personality_attributes;

  // Implementation

private:
  // Attributes

  // Implementation
  /**
   * @brief construct_personality_attributes
   */
  void construct_personality_attributes();

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
