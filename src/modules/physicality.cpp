/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/physicality.h>

// Application files
#include <utils/dice_rolls.h>

using physicality = his_gen::Attribute_enums::EPhysicality;
using repro = his_gen::Attribute_enums::EReproduction;

///////////////////////////////////////////////////////////////////////

his_gen::Physicality::Physicality()
  :
  Entity_attributes_base<Physicality, his_gen::Attribute_enums::EPhysicality>(),
  m_repro_attributes(construct_repro_attributes())
{
  Update_repro_dependent_attributes();
}

///////////////////////////////////////////////////////////////////////

his_gen::Physicality::Repro_attribute_map his_gen::Physicality::construct_repro_attributes()
{
  Repro_attribute_map repro_attributes;

  // Reproduction
  // TODO do more to handle intersex people, infertility, etc
  repro_attributes[repro::EREPRODUCTION_Can_sire_young] = his_gen::dice::Flip_a_coin();
  repro_attributes[repro::EREPRODUCTION_Can_bear_young] = !Can_sire_young();
  repro_attributes[repro::EREPRODUCTION_Can_nurse_young] = Can_bear_young();

  return repro_attributes;
}

///////////////////////////////////////////////////////////////////////

his_gen::Physicality::Physical_attribute_map his_gen::Physicality::construct_attributes()
{
  Physical_attribute_map physical_attributes;

  // Extremities
  physical_attributes[physicality::EPHYSICALITY_Hand_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Foot_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);

  // Chest
  physical_attributes[physicality::EPHYSICALITY_Nipple_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);

  // Body
  physical_attributes[physicality::EPHYSICALITY_Body_fat] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Muscle_mass] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Height] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Shoulder_width] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Stomach_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Hip_width] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Posture_straightness] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Waist_circumference] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);

  // Skin
  physical_attributes[physicality::EPHYSICALITY_Body_freckle_density] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Body_hair_density] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Skin_color] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Scar_coverage] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Skin_elasticity] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);

  // Voice
  physical_attributes[physicality::EPHYSICALITY_Voice_pitch] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);

  // Head and face
  physical_attributes[physicality::EPHYSICALITY_Cheekbone_prominence] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Ear_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Eye_color_saturation] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Eye_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Eye_spacing] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Facial_angularity] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Hair_length] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Hair_thickness] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Jawline_sharpness] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Lip_fullness] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  physical_attributes[physicality::EPHYSICALITY_Nose_size] = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);

  return physical_attributes;
}

///////////////////////////////////////////////////////////////////////

void his_gen::Physicality::Update_repro_dependent_attributes()
{
  // Physical attributes that are dependent on others
  uint8_t conditional_max = 1;
  if(Can_bear_young())
  {
    conditional_max = his_gen::ATTRIBUTE_MAX;
  }
  m_attributes[physicality::EPHYSICALITY_Breast_cleavage_depth] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);
  m_attributes[physicality::EPHYSICALITY_Breast_shape_roundness] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);
  m_attributes[physicality::EPHYSICALITY_Breast_size] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);
  m_attributes[physicality::EPHYSICALITY_Clitoris_size] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);
  m_attributes[physicality::EPHYSICALITY_Labia_major_size] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);
  m_attributes[physicality::EPHYSICALITY_Labia_minor_size] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);

  conditional_max = 1;
  if(Can_sire_young())
  {
    conditional_max = his_gen::ATTRIBUTE_MAX;
  }
  m_attributes[physicality::EPHYSICALITY_Penis_length] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);
  m_attributes[physicality::EPHYSICALITY_Penis_width] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);
  m_attributes[physicality::EPHYSICALITY_Testicle_size] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);

  conditional_max = 25;
  if(Can_sire_young())
  {
    conditional_max = his_gen::ATTRIBUTE_MAX;
  }
  m_attributes[physicality::EPHYSICALITY_Facial_hair_density] = his_gen::dice::Make_a_roll<uint8_t>(conditional_max);
}

///////////////////////////////////////////////////////////////////////

void his_gen::Physicality::Set_repro_attribute_value(const Attribute_enums::EReproduction repro_attribute,
                                                     const bool value)
{
  m_repro_attributes[repro_attribute] = value;
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Physicality::Can_bear_young()
{
  return m_repro_attributes[repro::EREPRODUCTION_Can_bear_young];
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Physicality::Can_sire_young()
{
  return m_repro_attributes[repro::EREPRODUCTION_Can_sire_young];
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Physicality::Can_nurse_young()
{
  return m_repro_attributes[repro::EREPRODUCTION_Can_nurse_young];
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Physicality::Get_repro_attribute_value(const Attribute_enums::EReproduction repro_attribute) const
{
  auto it = m_repro_attributes.find(repro_attribute);
  // Verify the attribute exists
  if(it == m_repro_attributes.end())
  {
    throw std::out_of_range("Attribute not found");
  }
  return it->second;
}

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Physicality& physicality)
{
  // Physicality
  nlohmann::json phys_attributes_converted;
  Physicality::Physical_attribute_map attributes = physicality.Get_attributes();
  for(auto it = attributes.begin(); it != attributes.end(); ++it)
  {
    phys_attributes_converted[his_gen::Attribute_enums::Get_entity_attribute_string(it->first)] = it->second;
  }
  json["physicality"] = phys_attributes_converted;

  // Repro
  nlohmann::json repro_attributes_converted;
  Physicality::Repro_attribute_map repro = physicality.Get_repro_attributes();
  for(auto it = repro.begin(); it != repro.end(); ++it)
  {
    repro_attributes_converted[his_gen::Attribute_enums::Get_entity_attribute_string(it->first)] = it->second;
  }
  json["reproduction"] = repro_attributes_converted;
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Physicality& physicality)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
