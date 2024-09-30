/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef PERSONALITY_ATTRACTION_H
#define PERSONALITY_ATTRACTION_H

// Standard libs

// Application files
#include <modules/personality.h>

namespace his_gen
{
/**
 * @brief
 */
class Personality_attraction : public Personality
{
public:
  // Attributes

  // Implementation
  /**
   * @brief
   * @param
   */
  Personality_attraction();

  /**
   * @brief Destructor
   */
  ~Personality_attraction(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief attracted_to_can_sire
   */
  bool attracted_to_can_sire{false};

  /**
   * @brief attracted_to_can_bear
   */
  bool attracted_to_can_bear{false};

  // Implementation

}; // class
}  // namespace his_gen

#endif // PERSONALITY_ATTRACTION_H
