/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/personality_attraction.h>

using personality_attribute = his_gen::Personality::Personality_attribute;

///////////////////////////////////////////////////////////////////////

his_gen::Personality_attraction::Personality_attraction(const Personality_attribute_map& entity_attributes)
  :
  Personality(),
  m_attraction_flexibility(derive_attraction_flexibility(entity_attributes)),
  m_attracted_to_can_sire(false),
  m_attracted_to_can_bear(false)
{

}

///////////////////////////////////////////////////////////////////////

int8_t his_gen::Personality_attraction::derive_attraction_flexibility(Personality_attribute_map attributes)
{
  int8_t attribute_totals = (
    (attributes[personality_attribute::PERSONALITY_ATTRIBUTE_Cooperative] * m_cooperative_coefficient) +
    (attributes[personality_attribute::PERSONALITY_ATTRIBUTE_Amiable] * m_amiable_coefficient) +
    (attributes[personality_attribute::PERSONALITY_ATTRIBUTE_Compassionate] * m_compassionate_coefficient) +
    (attributes[personality_attribute::PERSONALITY_ATTRIBUTE_Flexible] * m_flexible_coefficient)
  );
  return std::round(attribute_totals / m_coefficient_divisor);
}

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Personality_attraction& personality_attraction)
{
  nlohmann::to_json(json, static_cast<his_gen::Personality>(personality_attraction));
  json.update(
  {
    {"attracted_to_can_sire", personality_attraction.Get_attracted_to_can_sire()},
    {"attracted_to_can_bear", personality_attraction.Get_attracted_to_can_sire()},
    {"attraction_flexibility", personality_attraction.Get_attraction_flexibility()}
  });
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Personality_attraction& personality_attraction)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
