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
  Personality_attraction();

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
  int8_t m_attraction_flexibility;

  /**
   * @brief attracted_to_can_sire
   */
  bool m_attracted_to_can_sire{false};

  /**
   * @brief attracted_to_can_bear
   */
  bool m_attracted_to_can_bear{false};

  // Implementation
  /**
   * @brief derive_attraction_flexibility
   * @param attributes
   * @return
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
