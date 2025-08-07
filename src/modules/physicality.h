/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef PHYSICALITY_H
#define PHYSICALITY_H

// Standard libs
#include <variant>
#include <map>
#include <stdexcept>

// JSON
#include <deps/json.hpp>

// Application files
#include <defs/history_generator_defs.h>

namespace his_gen
{
/**
 * @brief Physical attributes for an entity with a body
 */
class Physicality
{
public:

  /**
   * @brief Physicality constructor
   */
  Physicality();

  /**
   * @brief Destructor
   */
  ~Physicality() = default;

  /**
   * @brief The Physical_attributes enum
   * @details Each of these attributes will represent a physical characteristic
   * for an entity with a body. Numeric values will be represented using 1 - 100.
   * These values don't correspond directly to any real-world measurements,
   * but rather represent this entity's attribute in relation to a general
   * average for that type of entity.
   */
  enum class Physical_attribute : uint8_t
  {
    PHYSICAL_ATTRIBUTE_Can_sire_young,          ///< [bool]
    PHYSICAL_ATTRIBUTE_Can_bear_young,          ///< [bool]
    PHYSICAL_ATTRIBUTE_Can_nurse_young,         ///< [bool]
    PHYSICAL_ATTRIBUTE_Hair_length,             ///< [uint]
    PHYSICAL_ATTRIBUTE_Hair_thickness,          ///< [uint]
    PHYSICAL_ATTRIBUTE_Hand_size,               ///< [uint]
    PHYSICAL_ATTRIBUTE_Foot_size,               ///< [uint]
    PHYSICAL_ATTRIBUTE_Nipple_size,             ///< [uint]
    PHYSICAL_ATTRIBUTE_Body_fat,                ///< [uint]
    PHYSICAL_ATTRIBUTE_Muscle_mass,             ///< [uint]
    PHYSICAL_ATTRIBUTE_Height,                  ///< [uint]
    PHYSICAL_ATTRIBUTE_Shoulder_width,          ///< [uint]
    PHYSICAL_ATTRIBUTE_Stomach_size,            ///< [uint]
    PHYSICAL_ATTRIBUTE_Hip_width,               ///< [uint]
    PHYSICAL_ATTRIBUTE_Waist_circumference,     ///< [uint]
    PHYSICAL_ATTRIBUTE_Posture_straightness,    ///< [uint]
    PHYSICAL_ATTRIBUTE_Body_freckle_density,    ///< [uint]
    PHYSICAL_ATTRIBUTE_Body_hair_density,       ///< [uint]
    PHYSICAL_ATTRIBUTE_Skin_color,              ///< [uint]
    PHYSICAL_ATTRIBUTE_Skin_elasticity,         ///< [uint]
    PHYSICAL_ATTRIBUTE_Scar_coverage,           ///< [uint]
    PHYSICAL_ATTRIBUTE_Voice_pitch,             ///< [uint]
    PHYSICAL_ATTRIBUTE_Facial_angularity,       ///< [uint]
    PHYSICAL_ATTRIBUTE_Cheekbone_prominence,    ///< [uint]
    PHYSICAL_ATTRIBUTE_Nose_size,               ///< [uint]
    PHYSICAL_ATTRIBUTE_Jawline_sharpness,       ///< [uint]
    PHYSICAL_ATTRIBUTE_Lip_fullness,            ///< [uint]
    PHYSICAL_ATTRIBUTE_Eye_size,                ///< [uint]
    PHYSICAL_ATTRIBUTE_Eye_spacing,             ///< [uint]
    PHYSICAL_ATTRIBUTE_Eye_color_saturation,    ///< [uint]
    PHYSICAL_ATTRIBUTE_Ear_size,                ///< [uint]
    PHYSICAL_ATTRIBUTE_Breast_size,             ///< [uint]
    PHYSICAL_ATTRIBUTE_Breast_shape_roundness,  ///< [uint]
    PHYSICAL_ATTRIBUTE_Breast_cleavage_depth,   ///< [uint]
    PHYSICAL_ATTRIBUTE_Labia_major_size,        ///< [uint]
    PHYSICAL_ATTRIBUTE_Labia_minor_size,        ///< [uint]
    PHYSICAL_ATTRIBUTE_Clitoris_size,           ///< [uint]
    PHYSICAL_ATTRIBUTE_Penis_length,            ///< [uint]
    PHYSICAL_ATTRIBUTE_Penis_width,             ///< [uint]
    PHYSICAL_ATTRIBUTE_Testicle_size,           ///< [uint]
    PHYSICAL_ATTRIBUTE_Facial_hair_density      ///< [uint]
  };

  /**
   * @brief The Unit enum, for specifying the value of a given
   * physical attribute.
   */
  enum class Unit : uint8_t
  {
    UNIT_Boolean, ///< A boolean
    UNIT_Scalar   ///< A scalar (ie numeric) value
  };

  /**
   * Usings
   */
  using Physical_attribute_value = std::variant<bool, uint8_t>;
  using Physical_attribute_maps = std::map<Physical_attribute, std::pair<Unit, Physical_attribute_value>>;

  /**
   * @brief Get the string representation of the physical attribute
   * @param physical_attribute The physical attribute to get
   * @return The string representation of the physical attribute
   */
  static std::string Get_phys_attribute_string(const Physical_attribute physical_attribute);

  /**
   * @brief Get a physical attribute from this class
   * @tparam T The return type, which will be the data type corresponding
   * to the Physical_attribute's Unit.
   * @param attribute The enumerated attribute to get
   * @return The value of this attribute
   */
  template<typename T>
  T Get_physical_attribute_value(const Physical_attribute attribute) const
  {
    auto it = m_physical_attributes.find(attribute);
    // Verify the attribute exists
    if(it == m_physical_attributes.end())
    {
      throw std::out_of_range("Attribute not found");
    }
    return std::get<T>(it->second.second);
  }

  /**
   * @brief Can_bear_young
   * @return
   */
  bool Can_bear_young();

  /**
   * @brief Can_sire_young
   * @return
   */
  bool Can_sire_young();

  /**
   * Getters and setters
   */
  Physical_attribute_maps Get_physical_attributes() const { return m_physical_attributes; }

protected:
  // Attributes
  /**
   * @brief The attributes and values for this entity
   */
  Physical_attribute_maps m_physical_attributes;

  // Implementation
  /**
   * @brief Set the value of this attribute
   * @param physical_attribute The enumerated physical attribute value
   * @param unit The unit for this value
   * @param value
   */
  void set_attribute(const Physical_attribute physical_attribute,
                     const Unit unit,
                     const Physical_attribute_value value);
private:
  // Attributes

  // Implementation

}; // class Physicality

/**
 * @brief to_json
 * @param json
 * @param physicality
 */
void to_json(nlohmann::json& json,
             const his_gen::Physicality& physicality);

/**
 * @brief from_json
 * @param json
 * @param physicality
 */
void from_json(const nlohmann::json& json,
               his_gen::Physicality& physicality);

}  // namespace his_gen

#endif // PHYSICALITY_H
