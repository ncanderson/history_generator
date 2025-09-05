/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORY_GENERATOR_DEFS_H
#define HISTORY_GENERATOR_DEFS_H

// Standard libs
#include <string>
#include <stdexcept>
#include <array>

// JSON

// Application files

namespace his_gen
{

/**
 * @brief Max value to use when generating attributes
 */
static const uint8_t ATTRIBUTE_MAX = 100;

/**
 * @brief Double version of the attribute max, used for dividing
 * when a double is necessary.
 */
static const double ATTRIBUTE_MAX_DOUBLE = static_cast<double>(ATTRIBUTE_MAX);

/**
 * @brief Generic helper allowing easier mapping of enums to strings
 * @details This helper struct will allow each enum to define a single
 * enum - string lookup and provide the enum/string conversion functions
 * without additional effort.
 * @tparam Enum The enum to map
 */
template <typename Enum_t>
struct Enum_mapping
{
  /**
   * @brief The enumerated value
   */
  Enum_t enum_value;

  /**
   * @brief The string representation of this enum
   */
  std::string_view enum_string;

  /**
   * @brief Constructor
   * @param enum_value The enum
   * @param enum_string The string representation of the enum
   */
  constexpr Enum_mapping(Enum_t enum_value,
                         std::string_view enum_string)
    :
    enum_value(enum_value),
    enum_string(enum_string)
  { }
};

/**
 * @brief A generic enum to string converter
 * @tparam Enum_t The enum to convert
 * @tparam S The size of the enum to convert (required for the array)
 * @param value The enumerated value to convert
 * @param table The enum to string mapping
 * @return A string_view of this enum.
 * @note The returned string_view is safe as long as the enum - string
 * mapping is defined somewhere. If those strings are not defined (like
 * loaded dynamically from file), these returned string_views may result
 * in dangling references.
 */
template <typename Enum_t, size_t S>
constexpr std::string_view Enum_to_string(Enum_t enum_value,
                                          const std::array<Enum_mapping<Enum_t>, S>& table)
{
  for(auto& enumerated : table)
  {
    if(enumerated.enum_value == enum_value)
    {
      return enumerated.enum_string;
    }
  }
  throw std::invalid_argument("Unknown enum value");
}

/**
 * @brief A generic string to enum converter
 * @tparam Enum_t The enum to get
 * @tparam S The size of the enum to convert (required for the array)
 * @param string The string to convert
 * @param table The enum to string mapping
 * @note Using a string_view is safe as long as the enum - string
 * mapping is defined somewhere. If those strings are not defined (like
 * loaded dynamically from file), these returned string_views may result
 * in dangling references.
 */
template <typename Enum_t, size_t S>
constexpr Enum_t String_to_enum(std::string_view enum_string,
                               const std::array<Enum_mapping<Enum_t>, S>& table)
{
  for(auto& enumerated : table)
  {
    if(enumerated.enum_string == enum_string)
    {
      return enumerated.enum_value;
    }
  }
  throw std::invalid_argument("Unknown enum string");
}

/**
 * @brief Make a string lowercase
 * @param input_string
 * @return The converted string
 */
std::string To_lowercase(const std::string& input_string);

/**
 * @brief The Era enum
 * @details Track the current position within the overall generation
 */
enum Era
{
  ERA_Unknown   = -1, ///< Unknown/init state
  ERA_Mythology = 0,  ///< Age of mythology, especially gods
  ERA_History   = 1,  ///< Age of history, mostly humans
  ERA_End_times = 2,  ///< Any wrap-up or post-generation tasks
  ERA_Terminate = 3   ///< End generation, terminate application
};

/**
 * @brief Get the current era
 * @param current_era The current era
 * @return The string representation of the current era
 */
std::string Get_current_era(Era current_era);

/**
 * @brief The Stage enum
 * @details Track steps taken within each generation era
 */
enum Stage
{
  STAGE_Init,      ///< Initialize and setup
  STAGE_Run,       ///< Execution of era generation
  STAGE_Terminate  ///< Wrap-up and transition
};

/**
 * @brief Get the current stage
 * @param current_stage The current stage
 * @return The string representation of the current stage
 */
std::string Get_current_stage(Stage current_stage);

}  // namespace his_gen

#endif // HISTORY_GENERATOR_DEFS_H
