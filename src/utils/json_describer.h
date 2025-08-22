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
    std::string paragraph;

    // Check for phsicality
    if (!entity.contains("physicality") || !entity["physicality"].contains("physicality"))
    {
      return "No physicality data found for this entity";
    }

    // Start
    paragraph += "This is the "
                 + entity["entity_type"].get<std::string>() + " "
                 + entity["name"].get<std::string>();

    if (entity.contains("title"))
    {
      paragraph += ", " + entity["title"].get<std::string>();
    }

    // Iterate attrs
    const auto &physicality_map = entity["physicality"]["physicality"];
    for (auto it = physicality_map.begin(); it != physicality_map.end(); ++it)
    {
      paragraph += "This entity's " + it.key() + " is " + classify_value(it.value()) + ". ";
    }

    paragraph += "==================================================";
    return paragraph.empty() ? "No physical attributes found." : paragraph;
  }

private:
  // Attributes

  // Implementation
  /**
   * @brief Take a JSON object and convert the value to a string
   * @param value The JSON value
   * @return
   */
  static std::string classify_value(const nlohmann::json &value)
  {
    if (!value.is_number_integer())
    {
      return "unknown";
    }

    // Define bounds
    int v = value.get<int>();
    if (v < 1) v = 1;
    if (v > 100) v = 100;

    // Map of the text output for each value
    static const std::map<int, std::string> classifications =
    {
      {0, "extremely tiny"},
      {1, "very small"},
      {2, "small"},
      {3, "below average in size"},
      {4, "slightly small"},
      {5, "average sized"},
      {6, "slightly large"},
      {7, "large"},
      {8, "very large"},
      {9, "extremely large"}
    };

    // Scale the attributes to the map range
    int index = (v - 1) / 10;
    // Get the text stub for the value
    return classifications.at(index);
  }

}; // class Json_Describer
}  // namespace his_gen

#endif // JSON_DESCRIBER_H
