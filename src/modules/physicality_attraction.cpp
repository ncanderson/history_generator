/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/physicality_attraction.h>

// Application files
#include <utils/dice_rolls.h>

///////////////////////////////////////////////////////////////////////

using personality = his_gen::Attribute_enums::EPersonality;
using physical_attraction = his_gen::Attribute_enums::EPhysicality;
using repro_attraction = his_gen::Attribute_enums::EReproduction;

///////////////////////////////////////////////////////////////////////

his_gen::Physicality_attraction::Physicality_attraction(const Personality& entity_personality)
  :
  Physicality(),
  m_physical_attraction_flexibility(derive_physical_attraction_flexibility(entity_personality))
{
  Physicality_attraction::Update_repro_dependent_attributes();
}

///////////////////////////////////////////////////////////////////////

void his_gen::Physicality_attraction::Update_repro_dependent_attributes()
{
  // Physical attributes that are dependent on others
  if(Attracted_to_bearing())
  {
    m_attributes[physical_attraction::EPHYSICALITY_Clitoris_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
    m_attributes[physical_attraction::EPHYSICALITY_Labia_major_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
    m_attributes[physical_attraction::EPHYSICALITY_Labia_minor_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  }

  if(Attracted_to_nursing())
  {
    m_attributes[physical_attraction::EPHYSICALITY_Breast_cleavage_depth] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
    m_attributes[physical_attraction::EPHYSICALITY_Breast_shape_roundness] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
    m_attributes[physical_attraction::EPHYSICALITY_Breast_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  }

  if(Attracted_to_siring())
  {
    m_attributes[physical_attraction::EPHYSICALITY_Penis_length] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
    m_attributes[physical_attraction::EPHYSICALITY_Penis_width] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
    m_attributes[physical_attraction::EPHYSICALITY_Testicle_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  }

  uint8_t conditional_max = 25;
  if(Attracted_to_siring())
  {
    conditional_max = his_gen::ATTRIBUTE_MAX;
  }
  m_attributes[physical_attraction::EPHYSICALITY_Facial_hair_density] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Physicality_attraction::Attracted_to_siring() const
{
  return Get_repro_attribute_value(repro_attraction::EREPRODUCTION_Can_sire_young);
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Physicality_attraction::Attracted_to_bearing() const
{
  return Get_repro_attribute_value(repro_attraction::EREPRODUCTION_Can_bear_young);
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Physicality_attraction::Attracted_to_nursing() const
{
  return Get_repro_attribute_value(repro_attraction::EREPRODUCTION_Can_nurse_young);
}

///////////////////////////////////////////////////////////////////////

int8_t his_gen::Physicality_attraction::derive_physical_attraction_flexibility(const Personality& personality)
{
  Personality::Personality_attribute_map personality_map = personality.Get_attributes();
  int8_t attribute_totals = (
      (personality_map[personality::EPERSONALITY_Excitable] * m_physical_excitable_coefficient) +
      (personality_map[personality::EPERSONALITY_Lustful] * m_physical_lustful_coefficient) +
      (personality_map[personality::EPERSONALITY_Extravagant] * m_physical_extravagant_coefficient)
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
