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

//// All personality trait pairs are to be defined here
//#define PERSONALITY_ATTRIBUTE_PAIRS(X) \
//  X(Aggressive, Passive)               \
//  X(Ambitious, Content)                \
//  X(Avoidant, Sociable)                \
//  X(Brave, Cowardly)                   \
//  X(Cooperative, Difficult)            \
//  X(Cruel, Kind)                       \
//  X(Decisive, Indecisive)              \
//  X(Diligent, Lazy)                    \
//  X(Flexible, Extremist)               \
//  X(Frank, Evasive)                    \
//  X(Generous, Selfish)                 \
//  X(Jealous, Compassionate)            \
//  X(Placid, Excitable)                 \
//  X(Thoughtful, Rash)                  \
//  X(Thrifty, Extravagant)              \
//  X(Argumentative, Amiable)            \
//  X(Witty, Humorless)                  \
//  X(Honest, Deceitful)                 \
//  X(Lustful, Chaste)
//
//// Macro to define the Personality_attribute enum
//#define GENERATE_PERSONALITY_ATTRIBUTE_ENUM()   \
//  enum class Personality_attribute : uint8_t    \
//  {                                             \
//    DEFINE_PERSONALITY_ATTRIBUTE_ENUM_ENTRIES() \
//  };
//
//// Macro to populate the Personality_attribute enum
//#define DEFINE_PERSONALITY_ATTRIBUTE_ENUM_ENTRIES() \
//  PERSONALITY_ATTRIBUTE_PAIRS(DEFINE_PERSONALITY_ATTRIBUTE_ENUM)
//
//// Macro to define the Personality_attribute enum entries
//#define DEFINE_PERSONALITY_ATTRIBUTE_ENUM(a, b) PERSONALITY_ATTRIBUTE_##a, PERSONALITY_ATTRIBUTE_##b
//
//// Define the map that will be used to hold the opposing personality attributes
//#define GENERATE_OPPOSING_PERSONALITY_ATTRIBUTE_MAP()                                   \
//  const std::map<Personality_attribute, Personality_attribute> m_personality_attributes \
//  {                                                                                     \
//    PERSONALITY_ATTRIBUTE_PAIRS(DEFINE_OPPOSITE_PERSONALITY_ATTRIBUTE_MAP)              \
//  };
//
//// Populate the map with the attribute pairs
//#define DEFINE_OPPOSITE_PERSONALITY_ATTRIBUTE_MAP(a, b)                                                 \
//{ Personality_attribute::PERSONALITY_ATTRIBUTE_##a, Personality_attribute::PERSONALITY_ATTRIBUTE_##b }, \
//{ Personality_attribute::PERSONALITY_ATTRIBUTE_##b, Personality_attribute::PERSONALITY_ATTRIBUTE_##a }, \

namespace his_gen
{
/**
 * @brief
 */
class Personality
{
public:
  // Attributes
  static const size_t Number_of_attributes;

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

  // TODO: Make this static so it's not duplicated on every instance of Personality on every entity
  // TODO: figure out some way to keep the pairs aligned? Maybe use a key for the
  // enum member's values, or a separate structure that keeps them together in
  // pairs?
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
   * @brief Get a personality attribute from this class
   * @param attribute The enumerated attribute to get
   * @return The value of this attribute
   */
  uint8_t Get_personality_attribute_value(const Personality_attribute attribute) const;

  /**
   * Getters and setters
   */
  //size_t Get_number_of_attributes() const { return Number_of_attributes; }
  Personality_attribute_map Get_attributes() const { return m_personality_attributes; }

  uint8_t Get_number_of_attributes() const { return m_num_attributes; }
  uint16_t Get_max_attribute_diff() const { return m_max_attribute_diff; }

protected:
  // Attributes
  /**
   * @brief All personality attributes with corresponding values
   */
  Personality_attribute_map m_personality_attributes;

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

private:
  // Attributes

  // Implementation
  /**
   * @brief construct_personality_attributes
   */
  Personality_attribute_map construct_personality_attributes();

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
