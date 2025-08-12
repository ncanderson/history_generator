/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/personality_attraction.h>

using personality_attribute = his_gen::Attribute_enums::EPersonality;

///////////////////////////////////////////////////////////////////////

his_gen::Personality_attraction::Personality_attraction(const Personality_attribute_map& entity_attributes)
  :
  Personality(),
  m_attraction_flexibility(derive_attraction_flexibility(entity_attributes)),
  m_attraction_risk_appetite(derive_risk_appetite(entity_attributes))
{ }

///////////////////////////////////////////////////////////////////////

int8_t his_gen::Personality_attraction::derive_attraction_flexibility(Personality_attribute_map attributes)
{
  int8_t attribute_totals = (
    (attributes[personality_attribute::EPERSONALITY_Cooperative] * m_cooperative_coefficient) +
    (attributes[personality_attribute::EPERSONALITY_Amiable] * m_amiable_coefficient) +
    (attributes[personality_attribute::EPERSONALITY_Compassionate] * m_compassionate_coefficient) +
    (attributes[personality_attribute::EPERSONALITY_Flexible] * m_flexible_coefficient)
  );
  return std::round(attribute_totals / m_coefficient_divisor);
}

///////////////////////////////////////////////////////////////////////

double his_gen::Personality_attraction::derive_risk_appetite(Personality_attribute_map attributes)
{
  double flexibility = attributes[personality_attribute::EPERSONALITY_Flexible];
  double bravery = attributes[personality_attribute::EPERSONALITY_Brave];
  double sociability = attributes[personality_attribute::EPERSONALITY_Sociable];
  double progressiveness = attributes[personality_attribute::EPERSONALITY_Progressive];

  // Weighted sum to determine stddev (0–100 scale)
  double openness_score = (0.5 * flexibility +
                           0.2 * bravery +
                           0.2 * sociability +
                           0.1 * progressiveness);

  // Returns a value between 5 and 25
  return 5.0 + (openness_score / his_gen::ATTRIBUTE_MAX) * 20.0;
}

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Personality_attraction& personality_attraction)
{
  nlohmann::to_json(json, static_cast<his_gen::Personality>(personality_attraction));
  json.update(
  {
    {"attraction_flexibility", personality_attraction.Get_personality_attraction_flexibility()},
    {"risk_appetite", personality_attraction.Get_risk_appetite()}
  });
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Personality_attraction& personality_attraction)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
