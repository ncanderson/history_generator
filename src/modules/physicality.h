/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef PHYSICALITY_H
#define PHYSICALITY_H

// Standard libs
#include <map>

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
   * for an entity with a body. Numeric values will be represented using 1 - his_gen::ATTRIBUTE_MAX.
   * These values don't correspond directly to any real-world measurements,
   * but rather represent this entity's attribute in relation to a general
   * average for that type of entity.
   */
  enum class Physical_attribute : uint8_t
  {
    PHYSICAL_ATTRIBUTE_Hair_length,
    PHYSICAL_ATTRIBUTE_Hair_thickness,
    PHYSICAL_ATTRIBUTE_Hand_size,
    PHYSICAL_ATTRIBUTE_Foot_size,
    PHYSICAL_ATTRIBUTE_Nipple_size,
    PHYSICAL_ATTRIBUTE_Body_fat,
    PHYSICAL_ATTRIBUTE_Muscle_mass,
    PHYSICAL_ATTRIBUTE_Height,
    PHYSICAL_ATTRIBUTE_Shoulder_width,
    PHYSICAL_ATTRIBUTE_Stomach_size,
    PHYSICAL_ATTRIBUTE_Hip_width,
    PHYSICAL_ATTRIBUTE_Waist_circumference,
    PHYSICAL_ATTRIBUTE_Posture_straightness,
    PHYSICAL_ATTRIBUTE_Body_freckle_density,
    PHYSICAL_ATTRIBUTE_Body_hair_density,
    PHYSICAL_ATTRIBUTE_Skin_color,
    PHYSICAL_ATTRIBUTE_Skin_elasticity,
    PHYSICAL_ATTRIBUTE_Scar_coverage,
    PHYSICAL_ATTRIBUTE_Voice_pitch,
    PHYSICAL_ATTRIBUTE_Facial_angularity,
    PHYSICAL_ATTRIBUTE_Cheekbone_prominence,
    PHYSICAL_ATTRIBUTE_Nose_size,
    PHYSICAL_ATTRIBUTE_Jawline_sharpness,
    PHYSICAL_ATTRIBUTE_Lip_fullness,
    PHYSICAL_ATTRIBUTE_Eye_size,
    PHYSICAL_ATTRIBUTE_Eye_spacing,
    PHYSICAL_ATTRIBUTE_Eye_color_saturation,
    PHYSICAL_ATTRIBUTE_Ear_size,
    PHYSICAL_ATTRIBUTE_Breast_size,
    PHYSICAL_ATTRIBUTE_Breast_shape_roundness,
    PHYSICAL_ATTRIBUTE_Breast_cleavage_depth,
    PHYSICAL_ATTRIBUTE_Labia_major_size,
    PHYSICAL_ATTRIBUTE_Labia_minor_size,
    PHYSICAL_ATTRIBUTE_Clitoris_size,
    PHYSICAL_ATTRIBUTE_Penis_length,
    PHYSICAL_ATTRIBUTE_Penis_width,
    PHYSICAL_ATTRIBUTE_Testicle_size,
    PHYSICAL_ATTRIBUTE_Facial_hair_density
  };

  /**
   * @brief The Physical_attributes enum
   * @details Each of these attributes will represent a reproductive characteristic
   * for an entity with a body.
   */
  enum class Repro_attribute : uint8_t
  {
    REPRO_ATTRIBUTE_Can_sire_young,
    REPRO_ATTRIBUTE_Can_bear_young,
    REPRO_ATTRIBUTE_Can_nurse_young
  };

  /**
   * Usings
   */
  using Physical_attribute_map = std::map<Physical_attribute, uint8_t>;
  using Repro_attribute_map = std::map<Repro_attribute, bool>;

  /**
   * @brief Get the string representation of the physical attribute
   * @param physical_attribute The physical attribute to get
   * @return The string representation of the physical attribute
   */
  static std::string Get_phys_attribute_string(const Physical_attribute physical_attribute);

  /**
   * @brief Get the string representation of the repro attribute
   * @param repro_attribute The repro attribute to get
   * @return The string representation of the repro attribute
   */
  static std::string Get_repro_attribute_string(const Repro_attribute repro_attribute);

  /**
   * @brief Get a physical attribute from this class
   * @param attribute The enumerated attribute to get
   * @return The value of this attribute
   */
  uint8_t Get_pysicality_attribute_value(const Physical_attribute attribute) const;

  /**
   * @brief Get a repro attribute from this class
   * @param attribute The enumerated attribute to get
   * @return The value of this attribute
   */
  bool Get_repro_attribute_value(const Repro_attribute repro_attribute) const;

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
  Physical_attribute_map Get_physical_attributes() const { return m_physical_attributes; }
  Repro_attribute_map Get_repro_attributes() const { return m_repro_attributes; }

  uint8_t Get_number_of_attributes() const { return m_num_attributes; }
  uint16_t Get_max_attribute_diff() const { return m_max_attribute_diff; }

protected:
  // Attributes
  /**
   * @brief The attributes and values for this entity
   */
  Physical_attribute_map m_physical_attributes;

  /**
   * @brief Reproductive attributes of this entity
   */
  Repro_attribute_map m_repro_attributes;

  // Implementation

private:
  // Attributes
  // TODO: Make this a static value since it won't change at runtime
  /**
   * @brief The number of attributes
   */
  uint8_t m_num_attributes;

  // TODO: Make this a static value since it won't change at runtime
  /**
   * @brief The maximum possible difference across all attributes
   */
  uint16_t m_max_attribute_diff;

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
