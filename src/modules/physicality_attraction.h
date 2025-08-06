/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef PHYSICALITY_ATTRACTION_H
#define PHYSICALITY_ATTRACTION_H

// Standard libs

// Application files
#include <modules/physicality.h>
#include <modules/personality.h>

namespace his_gen
{
/**
 * @brief The attributes governing this physical attraction.
 * @details As `Physicality` is randomized, this derived class
 * will create its own instance of `Physicality` to represent the attributes
 * that are attractive. Attraction flexibility is the mechanism
 * used to compare the two personalities.
 */
class Physicality_attraction : public Physicality
{
  // Attributes

  // Implementation

  /**
   * @brief Constructor
   */
  Physicality_attraction(const Personality& entity_personality);

  /**
   * @brief Destructor
   */
  ~Physicality_attraction(){};

  /**
   * Getters and setters
   */

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief m_attraction_flexibility
   */
  int8_t m_attraction_flexibility;

  // Implementation
  /**
   * @brief Return the attraction flexibility coefficient.
   * @details This value uses several personality traits to determine a coefficient
   * for attraction flexibility. This represents a buffer around traits that a
   * given entity will be attracted to.
   * @param attributes This enitity's attraction attributes
   * @return The attraction flexibility coefficient
   */
  int8_t derive_attraction_flexibility(const Personality& personality);

}; // class Physicality_attraction

/**
 * @brief to_json
 * @param json
 * @param physicality_attraction
 */
void to_json(nlohmann::json& json,
             const his_gen::Physicality_attraction& physicality_attraction);

/**
 * @brief from_json
 * @param json
 * @param physicality_attraction
 */
void from_json(const nlohmann::json& json,
               his_gen::Physicality_attraction& physicality_attraction);

}  // namespace his_gen

#endif // PHYSICALITY_ATTRACTION_H
