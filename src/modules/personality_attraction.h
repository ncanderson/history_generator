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
  Personality_attraction(std::map<Attribute, int8_t> entity_attributes);

  /**
   * @brief Destructor
   */
  ~Personality_attraction(){};

  /**
   * Getters and setters
   */
  bool Get_attracted_to_can_sire() const { return m_attracted_to_can_sire; }
  void Set_attracted_to_can_sire(bool attraction) { m_attracted_to_can_sire = attraction; }

  bool Get_attracted_to_can_bear() const { return m_attracted_to_can_bear; }
  void Set_attracted_to_can_bear(bool attraction) { m_attracted_to_can_bear = attraction; }

  int8_t Get_attraction_flexibility() const { return m_attraction_flexibility; }
  void Set_attraction_flexibility(int8_t attraction_flexibility) { m_attraction_flexibility = attraction_flexibility; }

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

  /**
   * @brief attracted_to_can_sire
   */
  bool m_attracted_to_can_sire;

  /**
   * @brief attracted_to_can_bear
   */
  bool m_attracted_to_can_bear;

  // Implementation
  /**
   * @brief Return the attraction flexibility coefficient.
   * @details This value uses several personality traits to determine a coefficient
   * for attraction flexibility. This represents a buffer around traits that a
   * given entity will be attracted to.
   * @param attributes This enitity's attraction attributes
   * @return The attraction flexibility coefficient
   */
  int8_t derive_attraction_flexibility(std::map<his_gen::Attribute, int8_t> attributes);

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
