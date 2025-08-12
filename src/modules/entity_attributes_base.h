/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_ATTRIBUTES_H
#define ENTITY_ATTRIBUTES_H

// Standard libs
#include <cstdint>
#include <string>
#include <stdexcept>
#include <map>

// JSON

// Application files

namespace his_gen
{
/**
 * @brief Enumerated entity attributes
 */
namespace Attribute_enums
{

// TODO: figure out some way to keep the pairs aligned? Maybe use a key for the
// enum member's values, or a separate structure that keeps them together in
// pairs?
/**
 * @brief The Personality attribute enum
 * @details Containing pairs of opposed personality attributes, this enum
 * will be used as the key for a given entity's personality map. Use the
 * Get_attribute_string function when outputing these attributes to the data
 * storage.
 */
enum class EPersonality : uint8_t
{
  EPERSONALITY_Aggressive,
  EPERSONALITY_Passive,
  EPERSONALITY_Ambitious,
  EPERSONALITY_Content,
  EPERSONALITY_Avoidant,
  EPERSONALITY_Sociable,
  EPERSONALITY_Brave,
  EPERSONALITY_Cowardly,
  EPERSONALITY_Cooperative,
  EPERSONALITY_Difficult,
  EPERSONALITY_Cruel,
  EPERSONALITY_Kind,
  EPERSONALITY_Decisive,
  EPERSONALITY_Indecisive,
  EPERSONALITY_Diligent,
  EPERSONALITY_Lazy,
  EPERSONALITY_Flexible,
  EPERSONALITY_Extremist,
  EPERSONALITY_Frank,
  EPERSONALITY_Evasive,
  EPERSONALITY_Generous,
  EPERSONALITY_Selfish,
  EPERSONALITY_Jealous,
  EPERSONALITY_Compassionate,
  EPERSONALITY_Placid,
  EPERSONALITY_Excitable,
  EPERSONALITY_Thoughtful,
  EPERSONALITY_Rash,
  EPERSONALITY_Thrifty,
  EPERSONALITY_Extravagant,
  EPERSONALITY_Argumentative,
  EPERSONALITY_Amiable,
  EPERSONALITY_Witty,
  EPERSONALITY_Humorless,
  EPERSONALITY_Honest,
  EPERSONALITY_Deceitful,
  EPERSONALITY_Lustful,
  EPERSONALITY_Chaste
}; // enum EPersonality

/**
   * @brief Get the string representation of a personality attribute enumeration
   * @param attr The attribute to get the string representation of
   * @return The string representation of `attribute`
   */
inline std::string Get_entity_attribute_string(const EPersonality personality_attribute)
{
  switch(personality_attribute)
  {
    case EPersonality::EPERSONALITY_Aggressive:    return "aggressive";
    case EPersonality::EPERSONALITY_Passive:       return "passive";
    case EPersonality::EPERSONALITY_Ambitious:     return "ambitious";
    case EPersonality::EPERSONALITY_Content:       return "content";
    case EPersonality::EPERSONALITY_Avoidant:      return "avoidant";
    case EPersonality::EPERSONALITY_Sociable:      return "sociable";
    case EPersonality::EPERSONALITY_Brave:         return "brave";
    case EPersonality::EPERSONALITY_Cowardly:      return "cowardly";
    case EPersonality::EPERSONALITY_Cooperative:   return "cooperative";
    case EPersonality::EPERSONALITY_Difficult:     return "difficult";
    case EPersonality::EPERSONALITY_Cruel:         return "cruel";
    case EPersonality::EPERSONALITY_Kind:          return "kind";
    case EPersonality::EPERSONALITY_Decisive:      return "decisive";
    case EPersonality::EPERSONALITY_Indecisive:    return "indecisive";
    case EPersonality::EPERSONALITY_Diligent:      return "diligent";
    case EPersonality::EPERSONALITY_Lazy:          return "lazy";
    case EPersonality::EPERSONALITY_Flexible:      return "flexible";
    case EPersonality::EPERSONALITY_Extremist:     return "extremist";
    case EPersonality::EPERSONALITY_Frank:         return "frank";
    case EPersonality::EPERSONALITY_Evasive:       return "evasive";
    case EPersonality::EPERSONALITY_Generous:      return "generous";
    case EPersonality::EPERSONALITY_Selfish:       return "selfish";
    case EPersonality::EPERSONALITY_Jealous:       return "jealous";
    case EPersonality::EPERSONALITY_Compassionate: return "compassionate";
    case EPersonality::EPERSONALITY_Placid:        return "placid";
    case EPersonality::EPERSONALITY_Excitable:     return "excitable";
    case EPersonality::EPERSONALITY_Thoughtful:    return "thoughtful";
    case EPersonality::EPERSONALITY_Rash:          return "rash";
    case EPersonality::EPERSONALITY_Thrifty:       return "thrifty";
    case EPersonality::EPERSONALITY_Extravagant:   return "extravagant";
    case EPersonality::EPERSONALITY_Argumentative: return "argumentative";
    case EPersonality::EPERSONALITY_Amiable:       return "amiable";
    case EPersonality::EPERSONALITY_Witty:         return "witty";
    case EPersonality::EPERSONALITY_Humorless:     return "humorless";
    case EPersonality::EPERSONALITY_Honest:        return "honest";
    case EPersonality::EPERSONALITY_Deceitful:     return "deceitful";
    case EPersonality::EPERSONALITY_Lustful:       return "lustful";
    case EPersonality::EPERSONALITY_Chaste:        return "chaste";
    default:
      // Unrecognized value
      throw std::invalid_argument("Attribute not found");
  }
}

///////////////////////////////////////////////////////////////////////

/**
   * @brief Enumerated physical attrbutes for an entity with a body
   * @details Each of these attributes will represent a physical characteristic
   * for an entity with a body. These values don't correspond directly to any
   * real-world measurements, but rather represent this entity's attribute in
   * relation to a general average for that type of entity.
   */
enum class EPhysicality : uint8_t
{
  EPHYSICALITY_Hair_length,
  EPHYSICALITY_Hair_thickness,
  EPHYSICALITY_Hand_size,
  EPHYSICALITY_Foot_size,
  EPHYSICALITY_Nipple_size,
  EPHYSICALITY_Body_fat,
  EPHYSICALITY_Muscle_mass,
  EPHYSICALITY_Height,
  EPHYSICALITY_Shoulder_width,
  EPHYSICALITY_Stomach_size,
  EPHYSICALITY_Hip_width,
  EPHYSICALITY_Waist_circumference,
  EPHYSICALITY_Posture_straightness,
  EPHYSICALITY_Body_freckle_density,
  EPHYSICALITY_Body_hair_density,
  EPHYSICALITY_Skin_color,
  EPHYSICALITY_Skin_elasticity,
  EPHYSICALITY_Scar_coverage,
  EPHYSICALITY_Voice_pitch,
  EPHYSICALITY_Facial_angularity,
  EPHYSICALITY_Cheekbone_prominence,
  EPHYSICALITY_Nose_size,
  EPHYSICALITY_Jawline_sharpness,
  EPHYSICALITY_Lip_fullness,
  EPHYSICALITY_Eye_size,
  EPHYSICALITY_Eye_spacing,
  EPHYSICALITY_Eye_color_saturation,
  EPHYSICALITY_Ear_size,
  EPHYSICALITY_Breast_size,
  EPHYSICALITY_Breast_shape_roundness,
  EPHYSICALITY_Breast_cleavage_depth,
  EPHYSICALITY_Labia_major_size,
  EPHYSICALITY_Labia_minor_size,
  EPHYSICALITY_Clitoris_size,
  EPHYSICALITY_Penis_length,
  EPHYSICALITY_Penis_width,
  EPHYSICALITY_Testicle_size,
  EPHYSICALITY_Facial_hair_density
}; // enum EPhysicality

/**
   * @brief Get the string representation of a physical attribute enumeration
   * @param attr The attribute to get the string representation of
   * @return The string representation of `attribute`
   */
inline std::string Get_entity_attribute_string(const EPhysicality physical_attribute)
{
  switch(physical_attribute)
  {
    case EPhysicality::EPHYSICALITY_Hair_length:            return "hair_length";
    case EPhysicality::EPHYSICALITY_Hair_thickness:         return "hair_thickness";
    case EPhysicality::EPHYSICALITY_Hand_size:              return "hand_size";
    case EPhysicality::EPHYSICALITY_Foot_size:              return "foot_size";
    case EPhysicality::EPHYSICALITY_Nipple_size:            return "nipple_size";
    case EPhysicality::EPHYSICALITY_Body_fat:               return "body_fat";
    case EPhysicality::EPHYSICALITY_Muscle_mass:            return "muscle_mass";
    case EPhysicality::EPHYSICALITY_Height:                 return "height";
    case EPhysicality::EPHYSICALITY_Shoulder_width:         return "should_width";
    case EPhysicality::EPHYSICALITY_Stomach_size:           return "stomach_size";
    case EPhysicality::EPHYSICALITY_Hip_width:              return "hip_width";
    case EPhysicality::EPHYSICALITY_Waist_circumference:    return "waist_circumference";
    case EPhysicality::EPHYSICALITY_Posture_straightness:   return "posture_straightness";
    case EPhysicality::EPHYSICALITY_Body_freckle_density:   return "body_freckle_density";
    case EPhysicality::EPHYSICALITY_Body_hair_density:      return "body_hair_density";
    case EPhysicality::EPHYSICALITY_Skin_color:             return "skin_color";
    case EPhysicality::EPHYSICALITY_Skin_elasticity:        return "skin_elasticity";
    case EPhysicality::EPHYSICALITY_Scar_coverage:          return "scar_coverage";
    case EPhysicality::EPHYSICALITY_Voice_pitch:            return "voice_pitch";
    case EPhysicality::EPHYSICALITY_Facial_angularity:      return "facial_angularity";
    case EPhysicality::EPHYSICALITY_Cheekbone_prominence:   return "cheekbone_prominence";
    case EPhysicality::EPHYSICALITY_Nose_size:              return "nose_size";
    case EPhysicality::EPHYSICALITY_Jawline_sharpness:      return "jawline_sharpness";
    case EPhysicality::EPHYSICALITY_Lip_fullness:           return "lip_fullness";
    case EPhysicality::EPHYSICALITY_Eye_size:               return "eye_size";
    case EPhysicality::EPHYSICALITY_Eye_spacing:            return "eye_spacing";
    case EPhysicality::EPHYSICALITY_Eye_color_saturation:   return "eye_color_saturation";
    case EPhysicality::EPHYSICALITY_Ear_size:               return "ear_size";
    case EPhysicality::EPHYSICALITY_Breast_size:            return "breast_size";
    case EPhysicality::EPHYSICALITY_Breast_shape_roundness: return "breast_shape_roundness";
    case EPhysicality::EPHYSICALITY_Breast_cleavage_depth:  return "breast_cleavage_depth";
    case EPhysicality::EPHYSICALITY_Labia_major_size:       return "labia_major_size";
    case EPhysicality::EPHYSICALITY_Labia_minor_size:       return "labia_minor_size";
    case EPhysicality::EPHYSICALITY_Clitoris_size:          return "clitoris_size";
    case EPhysicality::EPHYSICALITY_Penis_length:           return "penis_length";
    case EPhysicality::EPHYSICALITY_Penis_width:            return "penis_width";
    case EPhysicality::EPHYSICALITY_Testicle_size:          return "testicle_size";
    case EPhysicality::EPHYSICALITY_Facial_hair_density:    return "facial_hair_density";
    default:
      // Unrecognized value
      throw std::invalid_argument("Physical attribute not found");
  }
}

///////////////////////////////////////////////////////////////////////

/**
   * @brief The Reproduction attributes enum
   * @details Each of these attributes will represent a reproductive characteristic
   * for an entity with a body.
   */
enum class EReproduction : uint8_t
{
  EREPRODUCTION_Can_sire_young,
  EREPRODUCTION_Can_bear_young,
  EREPRODUCTION_Can_nurse_young
}; // enum EReproduction

/**
   * @brief Get the string representation of a reproductive attribute enumeration
   * @param attr The attribute to get the string representation of
   * @return The string representation of `attribute`
   */
inline std::string Get_entity_attribute_string(const EReproduction repro_attribute)
{
  switch(repro_attribute)
  {
    case EReproduction::EREPRODUCTION_Can_sire_young:  return "can_sire_young";
    case EReproduction::EREPRODUCTION_Can_bear_young:  return "can_bear_young";
    case EReproduction::EREPRODUCTION_Can_nurse_young: return "can_nurse_young";
    default:
      // Unrecognized value
      throw std::invalid_argument("Repro attribute not found");
  }
}

} // namespace Attribute_enums

/**
 * @brief Base class for any attribute container
 * @tparam Enum_type The enumerated attribute type
 */
template <typename Enum_type>
class Entity_attributes_base
{
public:
  /**
   * @brief Destructor
   */
  virtual ~Entity_attributes_base() = default;

  /**
   * @brief Get the attributes managed by the derived class
   * @return A map with the Enum_type as the key and a uint8_t as the value
   */
  virtual std::map<Enum_type, uint8_t> Get_attributes() const = 0;

  /**
   * @brief Implementing classes will use this function to return attribute values
   * @param attr The attribute to get a value for
   * @return The value of `attribute`
   */
  virtual uint8_t Get_entity_attribute_value(const Enum_type attribute) const = 0;

}; // class Entity_attributes_base
}  // namespace his_gen

#endif // ENTITY_ATTRIBUTES_H
