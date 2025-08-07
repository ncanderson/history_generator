/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/physicality_attraction.h>

using personality = his_gen::Personality::Personality_attribute;
using physical_attraction = his_gen::Physicality::Physical_attribute;

///////////////////////////////////////////////////////////////////////

his_gen::Physicality_attraction::Physicality_attraction(const Personality& entity_personality)
  :
  Physicality(),
  m_physical_attraction_flexibility(derive_physical_attraction_flexibility(entity_personality))
{ }

///////////////////////////////////////////////////////////////////////

bool his_gen::Physicality_attraction::Attracted_to_siring() const
{
  return Get_physical_attribute_value<bool>(physical_attraction::PHYSICAL_ATTRIBUTE_Can_sire_young);
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Physicality_attraction::Attracted_to_bearing() const
{
  return Get_physical_attribute_value<bool>(physical_attraction::PHYSICAL_ATTRIBUTE_Can_bear_young);
}

///////////////////////////////////////////////////////////////////////

int8_t his_gen::Physicality_attraction::derive_physical_attraction_flexibility(const Personality& personality)
{
  Personality::Personality_attribute_map personality_map = personality.Get_attributes();
  int8_t attribute_totals = (
      (personality_map[personality::PERSONALITY_ATTRIBUTE_Cooperative] * m_physical_excitable_coefficient) +
      (personality_map[personality::PERSONALITY_ATTRIBUTE_Amiable] * m_physical_lustful_coefficient)
  );
  return std::round(attribute_totals / m_physical_coefficient_divisor);
}

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Physicality_attraction& physicality_attraction)
{
  nlohmann::to_json(json, static_cast<his_gen::Physicality>(physicality_attraction));
  json.update(
  {
    {"attraction_flexibility", physicality_attraction.Get_physical_attraction_flexibility()}
  });
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Physicality_attraction& physicality_attraction)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
