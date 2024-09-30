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

  /**
   * @brief Get_attributes
   * @return
   */
  std::map<Attribute, int8_t> Get_attributes() const { return m_personality_attributes; }

protected:
  // Attributes

  // Implementation

private:  
  // Attributes

  /**
   * @brief All personality attributes with corresponding values
   */
  std::map<Attribute, int8_t> m_personality_attributes;

  // Implementation
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
