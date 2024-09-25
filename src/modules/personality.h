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

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Personality, m_test)

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  int m_test = 1;

  // Implementation

}; // class Personality
}  // namespace his_gen

#endif // PERSONAALITY_H
