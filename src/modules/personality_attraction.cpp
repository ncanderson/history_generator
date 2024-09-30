/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/personality_attraction.h>

///////////////////////////////////////////////////////////////////////

his_gen::Personality_attraction::Personality_attraction()
    :
    Personality(),
    m_attraction_flexibility(derive_attraction_flexibility(Get_attributes()))
{

}

///////////////////////////////////////////////////////////////////////

int8_t his_gen::Personality_attraction::derive_attraction_flexibility(std::map<his_gen::Attribute, int8_t> attributes)
{
  int8_t attribute_totals = (
    (attributes[his_gen::Attribute::ATTRIBUTE_Cooperative] * m_cooperative_coefficient) +
    (attributes[his_gen::Attribute::ATTRIBUTE_Amiable] * m_amiable_coefficient) +
    (attributes[his_gen::Attribute::ATTRIBUTE_Compassionate] * m_compassionate_coefficient) +
                             (attributes[his_gen::Attribute::ATTRIBUTE_Flexible] * m_flexible_coefficient));
  return attribute_totals / 10;
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

}

///////////////////////////////////////////////////////////////////////
// END OF FILE
