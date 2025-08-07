/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef PERSONALITY_ATTRACTION_H
#define PERSONALITY_ATTRACTION_H

// Standard libs
#include <stdint.h>

// Application files
#include <modules/personality.h>

namespace his_gen
{
/**
 * @brief The attributes governing this attraction.
 * @details As `Personality` is randomized, this derived class
 * will create its own instance of `Personality` to represent the attributes
 * that are attractive. Attraction flexibility is the mechanism
 * used to compare the two personalities.
 */
class Personality_attraction : public Personality
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Construct an attraction object
   * @details This class takes a personality and derives some attraction
   * attributes based on that personality, using this class's attributes
   * @param entity_attributes The attributes of the users personality
   */
  Personality_attraction(const Personality_attribute_map& entity_attributes);

  /**
   * @brief Destructor
   */
  ~Personality_attraction(){};

  /**
   * Getters and setters
   */
  int8_t Get_personality_attraction_flexibility() const { return m_attraction_flexibility; }
  void Set_personality_attraction_flexibility(int8_t attraction_flexibility) { m_attraction_flexibility = attraction_flexibility; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Attraction flexibility coefficient for 'amiable'
   */
  double m_amiable_coefficient = .3;

  /**
   * @brief Attraction flexibility coefficient for 'compassionate'
   */
  double m_compassionate_coefficient = .1;

  /**
   * @brief Attraction flexibility coefficient for 'cooperative'
   */
  double m_cooperative_coefficient = .1;

  /**
   * @brief Attraction flexibility coefficient for 'flexible'
   */
  double m_flexible_coefficient = .5;

  /**
   * @brief This divisor determines the maximum flexibility coefficient.
   * @details The maximum coefficient value will be the maximum attribute
   * score / m_coefficient_divisor.
   * | Divisor | Max Attr. Score | Max flexibility coefficient |
   * |---------|-----------------|-----------------------------|
   * | 10      | 100             | 10                          |
   * | 2       | 100             | 50                          |
   */
  double m_coefficient_divisor = 2;

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
  int8_t derive_attraction_flexibility(Personality_attribute_map attributes);

}; // class Personality_attraction

/**
 * @brief to_json
 * @param json
 * @param personality_attraction
 */
void to_json(nlohmann::json& json,
             const his_gen::Personality_attraction& personality_attraction);

/**
 * @brief from_json
 * @param json
 * @param personality_attraction
 */
void from_json(const nlohmann::json& json,
               his_gen::Personality_attraction& personality_attraction);

}  // namespace his_gen

#endif // PERSONALITY_ATTRACTION_H
