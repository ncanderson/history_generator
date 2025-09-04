/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef JSON_DESCRIBER_H
#define JSON_DESCRIBER_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <modules/entity_attributes_base.h>

namespace his_gen
{
/**
 * @class Utility class to output generated entities
 * in a descriptive text format
 */
class Json_describer
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Convert a JSON object to a paragraph
   * @param entity The entity to convert
   * @param output_genitals Some AI image generators won't output images
   * if certain physical features are described. Argue false to suppress those.
   * @return A converted paragraph describing this entity
   */
  static std::string Describe_physicality(const nlohmann::json &entity,
                                          const bool output_genitals = true);

private:
  // Attributes

  // Implementation
  /**
   * @brief Take a JSON object and convert the value to a string
   * @param value The JSON value
   * @return
   */
  static std::string classify_value(uint8_t v, Attribute_enums::EValue_type value_type);

  /**
   * @brief Format the output of some output text
   * @param input_string
   * @return
   */
  static std::string format_output(std::string& input_string);

}; // class Json_Describer
}  // namespace his_gen

#endif // JSON_DESCRIBER_H
