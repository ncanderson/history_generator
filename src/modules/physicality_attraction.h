/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef PHYSICALITY_ATTRACTION_H
#define PHYSICALITY_ATTRACTION_H

// Standard libs

// Application files
#include <modules/physicality.h>
#include <modules/personality.h>
#include <models/entities/entity_base.h>

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
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   * @brief entity_personality The entity's personality, used to check some
   * attributes related to physical attraction.
   */
  Physicality_attraction(const Personality& entity_personality);

  /**
   * @brief Destructor
   */
  ~Physicality_attraction(){};

  /**
   * @brief Attracted_to_siring
   * @return
   */
  bool Attracted_to_siring() const;

  /**
   * @brief Attracted_to_bearing
   * @return
   */
  bool Attracted_to_bearing() const;

  /**
   * @brief Attracted_to_nursing
   * @return
   */
  bool Attracted_to_nursing() const;

  /**
   * Getters and setters
   */
  int8_t Get_physical_attraction_flexibility() const { return m_physical_attraction_flexibility; }
  void Set_physical_attraction_flexibility(const int8_t physical_attraction_flexibility)
  {
    m_physical_attraction_flexibility = physical_attraction_flexibility;
  }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Attraction flexibility coefficient for 'excitable'
   */
  double m_physical_excitable_coefficient = .2;

  /**
   * @brief Attraction flexibility coefficient for 'extravagant'
   */
  double m_physical_extravagant_coefficient = .1;

  /**
   * @brief Attraction flexibility coefficient for 'compassionate'
   */
  double m_physical_lustful_coefficient = .7;

  /**
   * @brief This divisor determines the maximum flexibility coefficient.
   * @details The maximum coefficient value will be the maximum attribute
   * score / m_coefficient_divisor.
   * | Divisor | Max Attr. Score | Max flexibility coefficient |
   * |---------|-----------------|-----------------------------|
   * | 10      | 100             | 10                          |
   * | 2       | 100             | 50                          |
   */
  double m_physical_coefficient_divisor = 2;

  /**
   * @brief m_attraction_flexibility
   */
  int8_t m_physical_attraction_flexibility;

  // Implementation
  /**
   * @brief Return the attraction flexibility coefficient.
   * @details This value uses several personality traits to determine a coefficient
   * for attraction flexibility. This represents a buffer around traits that a
   * given entity will be attracted to.
   * @param attributes This enitity's attraction attributes
   * @return The attraction flexibility coefficient
   */
  int8_t derive_physical_attraction_flexibility(const Personality& personality);

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
