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

namespace his_gen
{
/**
 * @brief
 */
class Personality : public Entity_attributes_base<Personality, Attribute_enums::EPersonality>
{
  // This allows the base class to call the derived construct_attributes()
  friend class Entity_attributes_base<Personality, Attribute_enums::EPersonality>;

public:
  // Attributes
  static const size_t Number_of_attributes;

  // Implementation
  /**
   * @brief Default constructor
   */
  Personality();

  /**
   * @brief Destructor
   */
  ~Personality() = default;

  /**
   * Usings
   */
  using Personality_attribute_map = std::map<Attribute_enums::EPersonality, uint8_t>;

protected:
  // Attributes

  // Implementation
  /**
   * @brief Construct attributes for this personality
   */
  static Personality_attribute_map construct_attributes();

private:
  // Attributes

  // Implementation

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
