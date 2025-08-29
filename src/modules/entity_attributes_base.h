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
#include <vector>
#include <unordered_map>

// JSON

// Application files
#include <defs/history_generator_defs.h>
#include <utils/history_generator_utils.h>

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
  EPERSONALITY_Chaste,
  EPERSONALITY_Progressive,
  EPERSONALITY_Conservative
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
  EPHYSICALITY_Facial_hair_density,
  EPHYSICALITY_Butt_roundness
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
    case EPhysicality::EPHYSICALITY_Shoulder_width:         return "shoulder_width";
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
    case EPhysicality::EPHYSICALITY_Butt_roundness:         return "butt_roundness";
    default:
      // Unrecognized value
      throw std::invalid_argument("Physical attribute not found");
  }
}

///////////////////////////////////////////////////////////////////////

inline Attribute_enums::EPhysicality Get_entity_attribute(const std::string& attribute_name)
{
  static const std::unordered_map<std::string, Attribute_enums::EPhysicality> attribute_map =
  {
    {"hair_length", EPhysicality::EPHYSICALITY_Hair_length},
    {"hair_thickness", EPhysicality::EPHYSICALITY_Hair_thickness},
    {"hand_size", EPhysicality::EPHYSICALITY_Hand_size},
    {"foot_size", EPhysicality::EPHYSICALITY_Foot_size},
    {"nipple_size", EPhysicality::EPHYSICALITY_Nipple_size},
    {"body_fat", EPhysicality::EPHYSICALITY_Body_fat},
    {"muscle_mass", EPhysicality::EPHYSICALITY_Muscle_mass},
    {"height", EPhysicality::EPHYSICALITY_Height},
    {"shoulder_width", EPhysicality::EPHYSICALITY_Shoulder_width},
    {"stomach_size", EPhysicality::EPHYSICALITY_Stomach_size},
    {"hip_width", EPhysicality::EPHYSICALITY_Hip_width},
    {"waist_circumference", EPhysicality::EPHYSICALITY_Waist_circumference},
    {"posture_straightness", EPhysicality::EPHYSICALITY_Posture_straightness},
    {"body_freckle_density", EPhysicality::EPHYSICALITY_Body_freckle_density},
    {"body_hair_density", EPhysicality::EPHYSICALITY_Body_hair_density},
    {"skin_color", EPhysicality::EPHYSICALITY_Skin_color},
    {"skin_elasticity", EPhysicality::EPHYSICALITY_Skin_elasticity},
    {"scar_coverage", EPhysicality::EPHYSICALITY_Scar_coverage},
    {"voice_pitch", EPhysicality::EPHYSICALITY_Voice_pitch},
    {"facial_angularity", EPhysicality::EPHYSICALITY_Facial_angularity},
    {"cheekbone_prominence", EPhysicality::EPHYSICALITY_Cheekbone_prominence},
    {"nose_size", EPhysicality::EPHYSICALITY_Nose_size},
    {"jawline_sharpness", EPhysicality::EPHYSICALITY_Jawline_sharpness},
    {"lip_fullness", EPhysicality::EPHYSICALITY_Lip_fullness},
    {"eye_size", EPhysicality::EPHYSICALITY_Eye_size},
    {"eye_spacing", EPhysicality::EPHYSICALITY_Eye_spacing},
    {"eye_color_saturation", EPhysicality::EPHYSICALITY_Eye_color_saturation},
    {"ear_size", EPhysicality::EPHYSICALITY_Ear_size},
    {"breast_size", EPhysicality::EPHYSICALITY_Breast_size},
    {"breast_shape_roundness", EPhysicality::EPHYSICALITY_Breast_shape_roundness},
    {"breast_cleavage_depth", EPhysicality::EPHYSICALITY_Breast_cleavage_depth},
    {"labia_major_size", EPhysicality::EPHYSICALITY_Labia_major_size},
    {"labia_minor_size", EPhysicality::EPHYSICALITY_Labia_minor_size},
    {"clitoris_size", EPhysicality::EPHYSICALITY_Clitoris_size},
    {"penis_length", EPhysicality::EPHYSICALITY_Penis_length},
    {"penis_width", EPhysicality::EPHYSICALITY_Penis_width},
    {"testicle_size", EPhysicality::EPHYSICALITY_Testicle_size},
    {"facial_hair_density", EPhysicality::EPHYSICALITY_Facial_hair_density},
    {"butt_roundness", EPhysicality::EPHYSICALITY_Butt_roundness}
  };

  const std::string lc_attribute_name = his_gen::To_lowercase(attribute_name);

  auto it = attribute_map.find(lc_attribute_name);
  if (it != attribute_map.end())
  {
    return it->second;
  }
  else
  {
    his_gen::Print_to_cout(lc_attribute_name);
    throw std::invalid_argument("Can't find physicality attribute from string");
  }
}

///////////////////////////////////////////////////////////////////////

/**
 * @brief The EValueType enum, used to output text strings from attributes
 */
enum class EValue_type : uint8_t
{
  EVALUE_TYPE_Size,          ///< very small → very large
  EVALUE_TYPE_Density,       ///< absent → very dense
  EVALUE_TYPE_Pitch,         ///< low → high (voice)
  EVALUE_TYPE_Roundness,     ///< flat → very round (e.g., butt, breast)
  EVALUE_TYPE_Presence,      ///< absent → present (e.g., facial hair)
  EVALUE_TYPE_Other          ///< default
};

///////////////////////////////////////////////////////////////////////

/**
 * @brief physicality_value_type, mapping physical attributes to their value type
 */
static const std::map<EPhysicality, EValue_type> physicality_value_type =
{
  {EPhysicality::EPHYSICALITY_Hair_length,            EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Hair_thickness,         EValue_type::EVALUE_TYPE_Density},
  {EPhysicality::EPHYSICALITY_Hand_size,              EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Foot_size,              EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Nipple_size,            EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Body_fat,               EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Muscle_mass,            EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Height,                 EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Shoulder_width,         EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Stomach_size,           EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Hip_width,              EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Waist_circumference,    EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Posture_straightness,   EValue_type::EVALUE_TYPE_Other},
  {EPhysicality::EPHYSICALITY_Body_freckle_density,   EValue_type::EVALUE_TYPE_Density},
  {EPhysicality::EPHYSICALITY_Body_hair_density,      EValue_type::EVALUE_TYPE_Density},
  {EPhysicality::EPHYSICALITY_Skin_color,             EValue_type::EVALUE_TYPE_Other},
  {EPhysicality::EPHYSICALITY_Skin_elasticity,        EValue_type::EVALUE_TYPE_Other},
  {EPhysicality::EPHYSICALITY_Scar_coverage,          EValue_type::EVALUE_TYPE_Density},
  {EPhysicality::EPHYSICALITY_Voice_pitch,            EValue_type::EVALUE_TYPE_Pitch},
  {EPhysicality::EPHYSICALITY_Facial_angularity,      EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Cheekbone_prominence,   EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Nose_size,              EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Jawline_sharpness,      EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Lip_fullness,           EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Eye_size,               EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Eye_spacing,            EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Eye_color_saturation,   EValue_type::EVALUE_TYPE_Other},
  {EPhysicality::EPHYSICALITY_Ear_size,               EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Breast_size,            EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Breast_shape_roundness, EValue_type::EVALUE_TYPE_Roundness},
  {EPhysicality::EPHYSICALITY_Breast_cleavage_depth,  EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Labia_major_size,       EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Labia_minor_size,       EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Clitoris_size,          EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Penis_length,           EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Penis_width,            EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Testicle_size,          EValue_type::EVALUE_TYPE_Size},
  {EPhysicality::EPHYSICALITY_Facial_hair_density,    EValue_type::EVALUE_TYPE_Presence},
  {EPhysicality::EPHYSICALITY_Butt_roundness,         EValue_type::EVALUE_TYPE_Roundness}
};

///////////////////////////////////////////////////////////////////////

static const std::vector<std::string> size_descriptions =
{
  "far below average",
  "below average",
  "slightly below average",
  "average",
  "slightly above average",
  "above average",
  "well above average",
  "far above average"
};

static const std::vector<std::string> density_descriptions =
{
  "absent",
  "extremely sparse",
  "very sparse",
  "sparse",
  "moderate",
  "dense",
  "very dense",
  "extremely dense"
};

static const std::vector<std::string> presence_descriptions =
{
  "absent", "barely present", "present", "prominent"
};

static const std::vector<std::string> pitch_descriptions =
{
  "very low", "low", "slightly low", "medium pitch",
  "slightly high", "high", "very high"
};

static const std::vector<std::string> roundness_descriptions =
{
  "flat", "slightly rounded", "moderately rounded", "rounded",
  "very rounded", "extremely rounded"
};

static const std::vector<std::string> default_descriptions =
{
  "minimal", "low", "slightly low", "medium",
  "slightly high", "high", "very high"
};

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
 * @class Entity_attributes_base
 * @brief Base class template for managing enumerated attributes of an entity.
 *
 * @tparam Derived The derived class implementing this base.
 * @tparam Enum_type The enumerated type representing the entity's attributes.
 *
 * This class provides a standardized mechanism for derived classes to:
 *   - Store attributes in a uniform map keyed by an enumeration.
 *   - Retrieve attribute values safely.
 *   - Track meta-information such as the number of attributes and
 *     the maximum possible attribute score.
 *
 * Design Highlights:
 * 1. **Generic Attribute Storage**
 *    - Uses `std::map<Enum_type, uint8_t>` to store attribute values.
 *    - Provides `Get_entity_attribute_value()` and `Get_attributes()` for safe access.
 *
 * 2. **Attribute Meta-Data**
 *    - `m_num_attributes` stores the number of attributes.
 *    - `m_max_attribute_score` stores the maximum possible total score.
 *    - Automatically computed when `set_attributes()` is called.
 *
 * 3. **Enforcing Derived-Class Attribute Construction**
 *    - This base class requires that any derived class implements
 *      `construct_attributes()`, implementing its own attribute construction logic.
 *    - Enables derived classes to compute attributes based on instance-specific
 *      data (e.g., reproductive attributes in Physicality).
 *
 * Usage Pattern:
 *   - Define a derived class (e.g., Personality, Physicality) that implements
 *     `construct_attributes()`.
 *   - Access attributes via `Get_entity_attribute_value()` or `Get_attributes()`.
 *
 * #### Deriving a new attribute class from `Entity_attributes_base`
 *
 * `Entity_attributes_base` is a CRTP-style base class that handles common behavior for entities with enumerated attributes, including:
 *
 * - Storing the attribute map
 * - Providing getters for attributes, number of attributes, and maximum score
 * - Reducing boilerplate in constructors and initialization
 *
 * To create a new derived class:
 *
 * 1. **Define the attribute enum** (if not already defined) in the `Attribute_enums` namespace:
 *
 * ```cpp
 * enum class ENewAttribute : uint8_t
 * {
 *   ATTRIBUTE_ONE,
 *   ATTRIBUTE_TWO,
 *   ATTRIBUTE_THREE
 * };
 *
 * 2. Derive from the base class using CRTP:
 * @code
 * class NewEntity : public Entity_attributes_base<NewEntity, Attribute_enums::ENewAttribute>
 * @endcode
 *
 * Notes:
 * - **Static `construct_attributes()`**: Must be `static` so that the base class can call it
 *   during construction without needing a fully constructed instance.
 * - **CRTP Pattern**: `Derived` is passed as a template parameter to `Entity_attributes_base`.
 *   This allows the base to call `Derived::construct_attributes()` at compile time.
 * - **No runtime polymorphism**: This design is for compile-time code reuse and boilerplate
 *   reduction, not for virtual dispatch.
 * - **Adding extra attributes**: If your derived class has additional attribute sets
 *   (e.g., reproductive attributes in `Physicality`), you can initialize them in the derived constructor
 *   after the base class initialization.
 */
template<typename Derived, typename Enum_type>
class Entity_attributes_base
{
public:
  /**
   * Facilitate derived class map usage
   */
  using Attribute_map = std::map<Enum_type, uint8_t>;

  /**
   * @brief Destructor
   */
  virtual ~Entity_attributes_base() = default;

  /**
   * @brief Get_attributes
   * @return The map of attributes
   */
  const Attribute_map& Get_attributes() const { return m_attributes; }

  /**
   * @brief Get_number_of_attributes
   * @return
   */
  uint8_t Get_number_of_attributes() const { return m_num_attributes; }

  /**
   * @brief Get_max_attribute_diff
   * @return
   */
  uint16_t Get_max_attribute_diff() const { return m_max_attribute_score; }

  /**
     * @brief Get an attribute value from this entity
     * @details If an attribute is not found, a 0 will be returned. This will
     * result in the attraction difference increasing by whatever amount
     * the other entity is looking for.
     * @param attribute The enumerated attribute to get
     * @return The value of this attribute
     * @throws std::out_of_range Thrown if the attribute does not exist
     */
  uint8_t Get_entity_attribute_value(const Enum_type attribute) const
  {
    auto it = m_attributes.find(attribute);
    if (it == m_attributes.end())
    {
      return 0;
    }
    return it->second;
  }

  /**
   * @brief Set the value of an attribute
   * @param attribute The enumerated attribute to set
   * @param value The new value for this attribute
   * @throws std::out_of_range Thrown if the attribute does not exist
   */
  void Set_attribute_value(const Enum_type attribute, uint8_t value)
  {
    auto it = m_attributes.find(attribute);
    if (it == m_attributes.end())
    {
      throw std::out_of_range("Attribute not found");
    }
    it->second = value;
  }

protected:

  /**
   * @brief m_attributes
   */
  Attribute_map m_attributes;

  /**
   * @brief m_num_attributes
   */
  uint8_t m_num_attributes;

  /**
   * @brief Maximum possible score of all attributes
   */
  uint16_t m_max_attribute_score;

  // Implementation
  /**
   * @brief Entity_attributes_base
   */
  Entity_attributes_base()
    :
    m_attributes(Derived::construct_attributes()),
    m_num_attributes(m_attributes.size()),
    m_max_attribute_score(calc_max_attribute_score())
  { }

  /**
   * @brief Calculate the maximum
   * @return
   */
  uint16_t calc_max_attribute_score() const
  {
    return m_attributes.size() * his_gen::ATTRIBUTE_MAX;
  }

}; // class Entity_attribute_base
}  // namespace his_gen

#endif // ENTITY_ATTRIBUTES_H
