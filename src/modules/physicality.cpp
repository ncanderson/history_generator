/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/physicality.h>

// Application files
#include <utils/dice_rolls.h>

///////////////////////////////////////////////////////////////////////

his_gen::Physicality::Physicality()
  :
  m_physical_attributes()
{
  // Reproduction
  // TODO do more to handle intersex people, infertility, etc
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Can_sire_young,
                Unit::UNIT_Boolean,
                his_gen::dice::Flip_a_coin());
  // Bear young is the inverse of sire young
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Can_bear_young,
                Unit::UNIT_Boolean,
                !get_attribute<bool>(Physical_attribute::PHYSICAL_ATTRIBUTE_Can_sire_young));
  // Nurse young is the same as bear young
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Can_nurse_young,
                Unit::UNIT_Boolean,
                get_attribute<bool>(Physical_attribute::PHYSICAL_ATTRIBUTE_Can_bear_young));

  // Extremities
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Hand_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Foot_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));

  // Chest
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Nipple_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));

  // Body
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Body_fat,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Muscle_mass,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Height,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Shoulder_width,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Stomach_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Hip_width,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Waist_circumference,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Posture_straightness,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));

  // Skin
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Body_freckle_density,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Body_hair_density,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Skin_color,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Skin_elasticity,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Scar_coverage,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));

  // Voice
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Voice_pitch,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));

  // Head and face
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Facial_angularity,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Cheekbone_prominence,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Nose_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Jawline_sharpness,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Lip_fullness,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Eye_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Eye_spacing,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Eye_color_saturation,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Ear_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Hair_length,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Hair_thickness,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(100));

  // Physical attributes that are dependent on others
  uint8_t conditional_max = 1;
  if(get_attribute<bool>(Physical_attribute::PHYSICAL_ATTRIBUTE_Can_nurse_young))
  {
    conditional_max = 100;
  }
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Breast_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Breast_shape_roundness,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Breast_cleavage_depth,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max));

  conditional_max = 1;
  if(get_attribute<bool>(Physical_attribute::PHYSICAL_ATTRIBUTE_Can_bear_young))
  {
    conditional_max = 100;
  }
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Labia_major_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Labia_minor_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Clitoris_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max));

  conditional_max = 1;
  if(get_attribute<bool>(Physical_attribute::PHYSICAL_ATTRIBUTE_Can_sire_young))
  {
    conditional_max = 100;
  }
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Penis_length,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Penis_width,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max));
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Testicle_size,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max));

  conditional_max = 25;
  if(get_attribute<bool>(Physical_attribute::PHYSICAL_ATTRIBUTE_Can_sire_young))
  {
    conditional_max = 100;
  }
  set_attribute(Physical_attribute::PHYSICAL_ATTRIBUTE_Facial_hair_density,
                Unit::UNIT_Scalar,
                his_gen::dice::Make_a_roll<uint8_t>(conditional_max ));
}

///////////////////////////////////////////////////////////////////////

void his_gen::Physicality::set_attribute(const Physical_attribute physical_attribute,
                                         const Unit unit,
                                         const Physical_attribute_value value)
{
  // If boolean but value arg is not a boolean
  if(unit == Unit::UNIT_Boolean && !std::holds_alternative<bool>(value))
  {
    throw std::invalid_argument("Expected boolean value for this attribute");
  }

  // If not a boolean and value arg is not a double. This will allow further
  // expansion of the Units enumeration for things like degrees, length, etc.
  if(unit != Unit::UNIT_Boolean && !std::holds_alternative<uint8_t>(value))
  {
    throw std::invalid_argument("Expected numeric value for this attribute");
  }
  m_physical_attributes[physical_attribute] = std::make_pair(unit, value);
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Physicality::Get_phys_attribute_string(const Physical_attribute physical_attribute)
{
  switch(physical_attribute)
  {
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Can_sire_young:         return "can_sire_young";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Can_bear_young:         return "can_bear_young";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Can_nurse_young:        return "can_nurse_young";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Hair_length:            return "hair_length";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Hair_thickness:         return "hair_thickness";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Hand_size:              return "hand_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Foot_size:              return "foot_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Nipple_size:            return "nipple_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Body_fat:               return "body_fat";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Muscle_mass:            return "muscle_mass";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Height:                 return "height";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Shoulder_width:         return "should_width";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Stomach_size:           return "stomach_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Hip_width:              return "hip_width";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Waist_circumference:    return "waist_circumference";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Posture_straightness:   return "posture_straightness";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Body_freckle_density:   return "body_freckle_density";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Body_hair_density:      return "body_hair_density";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Skin_color:             return "skin_color";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Skin_elasticity:        return "skin_elasticity";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Scar_coverage:          return "scar_coverage";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Voice_pitch:            return "voice_pitch";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Facial_angularity:      return "facial_angularity";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Cheekbone_prominence:   return "cheekbone_prominence";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Nose_size:              return "nose_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Jawline_sharpness:      return "jawline_sharpness";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Lip_fullness:           return "lip_fullness";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Eye_size:               return "eye_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Eye_spacing:            return "eye_spacing";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Eye_color_saturation:   return "eye_color_saturation";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Ear_size:               return "ear_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Breast_size:            return "breast_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Breast_shape_roundness: return "breast_shape_roundness";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Breast_cleavage_depth:  return "breast_cleavage_depth";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Labia_major_size:       return "labia_major_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Labia_minor_size:       return "labia_minor_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Clitoris_size:          return "clitoris_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Penis_length:           return "penis_length";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Penis_width:            return "penis_width";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Testicle_size:          return "testicle_size";
    case Physical_attribute::PHYSICAL_ATTRIBUTE_Facial_hair_density:    return "facial_hair_density";
    default:
      // Unrecognized value
      throw std::invalid_argument("Physical attribute not found");
  }
}

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Physicality& physicality)
{
  nlohmann::json attributes_converted;
  Physicality::Physical_attribute_maps attributes = physicality.Get_physical_attributes();

  // Loop over all attributes in the map
  for(auto it = attributes.begin(); it != attributes.end(); ++it)
  {
    // Use a lambda to handle the different data types (which are in the Unit enum)
    std::visit([&attributes_converted, &it](const auto& value)
    {
      // Convert the value to an integer for JSON conversion
      attributes_converted[Physicality::Get_phys_attribute_string(it->first)] = static_cast<uint8_t>(value);
    }, it->second.second);
  }

  json = nlohmann::json
  {
    {"physicality", attributes_converted}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Physicality& physicality)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
