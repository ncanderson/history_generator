/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard libs
#include <string>
#include <vector>
#include <algorithm>

// JSON

// Application files
#include <utils/json_describer.h>

///////////////////////////////////////////////////////////////////////

using attrs = his_gen::Attribute_enums::EPhysicality;

///////////////////////////////////////////////////////////////////////

std::string his_gen::Json_describer::Describe_physicality(const nlohmann::json &entity,
                                                          const bool output_genitals)
{
  if (!entity.contains("physicality") || !entity["physicality"].contains("physicality"))
  {
    return "No physicality data found for this entity";
  }

  // The text string to build
  std::string paragraph;

  // Entity info
  paragraph += "This is a detailed, realistic photograph of the "
               + entity["entity_type"].get<std::string>() + " "
               + entity["name"].get<std::string>();

  if (entity.contains("title"))
  {
    paragraph += ", " + entity["title"].get<std::string>();
  }
  paragraph += ". ";

  // Clothing
  paragraph += "She is clothed in sheer black silk and heeled boots. ";
  // Location
  paragraph += "She stands surrounded by her favorite things, brightly lit in the afternoon sun.";

  // Attributes
  const auto& physicality_map = entity["physicality"]["physicality"];

  // Attrs to exclude
  static const std::vector<attrs> excluded_attrs = {
      attrs::EPHYSICALITY_Breast_cleavage_depth,
      attrs::EPHYSICALITY_Breast_shape_roundness,
      attrs::EPHYSICALITY_Breast_size,
      attrs::EPHYSICALITY_Clitoris_size,
      attrs::EPHYSICALITY_Testicle_size,
      attrs::EPHYSICALITY_Penis_length,
      attrs::EPHYSICALITY_Penis_width,
      attrs::EPHYSICALITY_Labia_major_size,
      attrs::EPHYSICALITY_Labia_minor_size,
      attrs::EPHYSICALITY_Nipple_size
  };

  for (auto it = physicality_map.begin(); it != physicality_map.end(); ++it)
  {
    if(!output_genitals)
    {
      // skip excluded values
      auto enum_val = his_gen::Attribute_enums::Get_entity_attribute(it.key());
      if (std::find(excluded_attrs.begin(), excluded_attrs.end(), enum_val) != excluded_attrs.end())
      {
        continue;
      }
    }

    // Lookup the enum corresponding to this attribute key
    attrs attr_enum = Attribute_enums::Get_entity_attribute(it.key());

    Attribute_enums::EValue_type value_type = Attribute_enums::EValue_type::EVALUE_TYPE_Other;
    auto map_it = Attribute_enums::physicality_value_type.find(attr_enum);
    if (map_it != Attribute_enums::physicality_value_type.end())
    {
      value_type = map_it->second;
    }

    int attr_value = it.value().get<uint8_t>();
    std::string key_string = it.key();
    paragraph += "Her " + format_output(key_string) + " is " + classify_value(attr_value, value_type) + ". ";
  }

  paragraph += "\n==================================================\n";

  return paragraph + "\n";
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Json_describer::classify_value(uint8_t v,
                                                    Attribute_enums::EValue_type value_type)
{
  // Enforce bounds
  if (v < 1) v = 1;
  if (v > 100) v = 100;


  uint8_t index = 0;
  std::string text;
  switch (value_type)
  {
    case Attribute_enums::EValue_type::EVALUE_TYPE_Size:
      index = (v - 1) * Attribute_enums::size_descriptions.size() / 100;
      text = Attribute_enums::size_descriptions[index];
      break;
    case Attribute_enums::EValue_type::EVALUE_TYPE_Density:
      index = (v - 1) * Attribute_enums::density_descriptions.size() / 100;
      text = Attribute_enums::size_descriptions[index];
      break;
    case Attribute_enums::EValue_type::EVALUE_TYPE_Presence:
      index = (v - 1) * Attribute_enums::presence_descriptions.size() / 100;
      text = Attribute_enums::size_descriptions[index];
      break;
    case Attribute_enums::EValue_type::EVALUE_TYPE_Pitch:
      index = (v - 1) * Attribute_enums::pitch_descriptions.size() / 100;
      text = Attribute_enums::size_descriptions[index];
      break;
    case Attribute_enums::EValue_type::EVALUE_TYPE_Roundness:
      index = (v - 1) * Attribute_enums::roundness_descriptions.size() / 100;
      text = Attribute_enums::size_descriptions[index];
      break;
    case Attribute_enums::EValue_type::EVALUE_TYPE_Other:
    default:
      index = (v - 1) * Attribute_enums::default_descriptions.size() / 100;
      text = Attribute_enums::size_descriptions[index];
      break;
  }
  // Replace underscores

  return format_output(text);
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Json_describer::format_output(std::string& input_string)
{
  std::replace(input_string.begin(), input_string.end(), '_', ' ');
  return input_string;
}

///////////////////////////////////////////////////////////////////////
