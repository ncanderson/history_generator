/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef JSON_DESCRIBER_H
#define JSON_DESCRIBER_H

// Standard libs
#include <string>
#include <vector>

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
   * @return A converted paragraph describing this entity
   */
  static std::string Describe_physicality(const nlohmann::json &entity)
  {
    if (!entity.contains("physicality") || !entity["physicality"].contains("physicality"))
    {
      return "No physicality data found for this entity";
    }

    std::string paragraph;

    // Entity info
    paragraph += "This is the "
                 + entity["entity_type"].get<std::string>() + " "
                 + entity["name"].get<std::string>();

    if (entity.contains("title"))
    {
      paragraph += ", " + entity["title"].get<std::string>();
    }
    paragraph += ". ";

    // Attributes
    const auto &physicality_map = entity["physicality"]["physicality"];
    for (auto it = physicality_map.begin(); it != physicality_map.end(); ++it)
    {
      // Lookup the enum corresponding to this attribute key
      Attribute_enums::EPhysicality attr_enum = Attribute_enums::Get_entity_attribute(it.key());

      Attribute_enums::EValue_type value_type = Attribute_enums::EValue_type::EVALUE_TYPE_Other;
      auto map_it = Attribute_enums::physicality_value_type.find(attr_enum);
      if (map_it != Attribute_enums::physicality_value_type.end())
      {
        value_type = map_it->second;
      }

      int attr_value = it.value().get<int>();
      paragraph += "Their " + it.key() + " is " + classify_value(attr_value, value_type) + ". ";
    }

    paragraph += "\n==================================================\n";

    return paragraph + "\n";
  }

private:
  // Attributes

  // Implementation
  /**
   * @brief Take a JSON object and convert the value to a string
   * @param value The JSON value
   * @return
   */
  static std::string classify_value(int v, Attribute_enums::EValue_type value_type)
  {
    if (v < 1) v = 1;
    if (v > 100) v = 100;

    int index = 0;
    switch (value_type)
    {
      case Attribute_enums::EValue_type::EVALUE_TYPE_Size:
        index = (v - 1) * Attribute_enums::size_descriptions.size() / 100;
        return Attribute_enums::size_descriptions[index];
      case Attribute_enums::EValue_type::EVALUE_TYPE_Density:
        index = (v - 1) * Attribute_enums::density_descriptions.size() / 100;
        return Attribute_enums::density_descriptions[index];
      case Attribute_enums::EValue_type::EVALUE_TYPE_Presence:
        index = (v - 1) * Attribute_enums::presence_descriptions.size() / 100;
        return Attribute_enums::presence_descriptions[index];
      case Attribute_enums::EValue_type::EVALUE_TYPE_Pitch:
        index = (v - 1) * Attribute_enums::pitch_descriptions.size() / 100;
        return Attribute_enums::pitch_descriptions[index];
      case Attribute_enums::EValue_type::EVALUE_TYPE_Roundness:
        index = (v - 1) * Attribute_enums::roundness_descriptions.size() / 100;
        return Attribute_enums::roundness_descriptions[index];
      case Attribute_enums::EValue_type::EVALUE_TYPE_Other:
      default:
        index = (v - 1) * Attribute_enums::default_descriptions.size() / 100;
        return Attribute_enums::default_descriptions[index];
    }
  }

}; // class Json_Describer
}  // namespace his_gen

#endif // JSON_DESCRIBER_H
