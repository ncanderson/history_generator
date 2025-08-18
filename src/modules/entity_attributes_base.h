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
#include <limits>

// JSON

// Application files
#include <defs/history_generator_defs.h>

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
     * @param attribute The enumerated attribute to get
     * @return The value of this attribute
     * @throws std::out_of_range Thrown if the attribute does not exist
     */
  uint8_t Get_entity_attribute_value(const Enum_type attribute) const
  {
    auto it = m_attributes.find(attribute);
    if (it == m_attributes.end())
    {
      throw std::out_of_range("Attribute not found");
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
    m_num_attributes(),
    m_max_attribute_score() {}

  /**
   * @brief Set the internal attribute map, number of attributes,
   * and the maximum attribute score for use in attraction determination.
   * @param attrs The map of attributes to initialize
   * @throws std::logic_error Thrown if attributes are already initialized
   */
  void set_attributes(const Attribute_map& attributes)
  {
    if (!m_attributes.empty())
    {
      throw std::logic_error("Attributes already initialized");
    }
    m_attributes = attributes;
    m_num_attributes = m_attributes.size();
    m_max_attribute_score = m_num_attributes * his_gen::ATTRIBUTE_MAX;
  }

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
