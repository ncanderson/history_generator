/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef PERSONALITY_H
#define PERSONALITY_H

// Standard libs

// JSON
#include <deps/json.hpp>

// Application files
#include <modules/entity_attributes_base.h>
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
class Personality : public Entity_attributes_base<Attribute_enums::EPersonality>
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

  /**
   * Usings
   */
  using Personality_attribute_map = std::map<Attribute_enums::EPersonality, uint8_t>;

  /**
   * @brief Get a personality attribute from this class
   * @param attribute The enumerated attribute to get
   * @return The value of this attribute
   */
  uint8_t Get_entity_attribute_value(const Attribute_enums::EPersonality attribute) const override;

  /**
   * Getters and setters
   */
  //size_t Get_number_of_attributes() const { return Number_of_attributes; }
  Personality_attribute_map Get_attributes() const override { return m_personality_attributes; }

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
