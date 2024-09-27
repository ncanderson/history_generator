/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef PERSONAALITY_H
#define PERSONAALITY_H

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
  int Test = 1;

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

#endif // PERSONAALITY_H
