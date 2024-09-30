/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORY_GENERATOR_DEFS_H
#define HISTORY_GENERATOR_DEFS_H

// Standard libraries
#include <string>

namespace his_gen
{

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
  ERA_Terminate = 3   ///< End generation terminate application
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

/**
 * @brief The Data_access_type enum
 * @details Determine the type of data source we'll be accessing
 */
enum Data_access_type
{
  DATA_ACCESS_TYPE_Unknown,  ///< Unknown data access type
  DATA_ACCESS_TYPE_File,     ///< File
  DATA_ACCESS_TYPE_Postgres  ///< PostgreSQL database
};

/**
 * @brief Get the current data access type
 * @param data_access_type The current data access type
 * @return The string representation of the access type
 */
std::string Get_data_access_type(Data_access_type data_access_type);

/**
 * @brief Get enumerated data access type from a string
 * @param data_access_type The string representation of the access type
 * @return String access type enumeration
 */
his_gen::Data_access_type Get_data_access_type(std::string data_access_type);

/**
 * @brief Struct to hold the details necessary to create a file data connection
 */
struct DAL_file_params
{
  /**
   * @brief Data file name
   */
  std::string filename;

  /**
   * @brief Path to data file to load
   */
  std::string file_path;
}; // struct DAL_file_details

/**
 * @brief Struct to hold the details necessary to create a PostgreSQL data
 * connection
 */
struct DAL_PG_params
{
  /**
   * @brief Database name
   */
  std::string db_name;

}; // struct DAL_PG_details

// TODO: figure out some way to keep the pairs aligned? Maybe use a key for the
// enum member's values, or a separate structure that keeps them together in
// pairs?
/**
   * @brief The Attribute enum
   * @details Containing pairs of opposed personality attributes, this enum
   * will be used as the key for a given entity's personality map. Use the
   * Get_attribute_string function when outputing these attributes to the data
   * storage.
   */
enum Attribute
{
  ATTRIBUTE_Aggressive,
  ATTRIBUTE_Passive,
  ATTRIBUTE_Ambitious,
  ATTRIBUTE_Content,
  ATTRIBUTE_Avoidant,
  ATTRIBUTE_Sociable,
  ATTRIBUTE_Brave,
  ATTRIBUTE_Cowardly,
  ATTRIBUTE_Cooperative,
  ATTRIBUTE_Difficult,
  ATTRIBUTE_Cruel,
  ATTRIBUTE_Kind,
  ATTRIBUTE_Decisive,
  ATTRIBUTE_Indecisive,
  ATTRIBUTE_Diligent,
  ATTRIBUTE_Lazy,
  ATTRIBUTE_Flexible,
  ATTRIBUTE_Extremist,
  ATTRIBUTE_Frank,
  ATTRIBUTE_Evasive,
  ATTRIBUTE_Generous,
  ATTRIBUTE_Selfish,
  ATTRIBUTE_Jealous,
  ATTRIBUTE_Compassionate,
  ATTRIBUTE_Placid,
  ATTRIBUTE_Excitable,
  ATTRIBUTE_Thoughtful,
  ATTRIBUTE_Rash,
  ATTRIBUTE_Thrifty,
  ATTRIBUTE_Extravagant,
  ATTRIBUTE_Argumentative,
  ATTRIBUTE_Amiable,
  ATTRIBUTE_Witty,
  ATTRIBUTE_Humorless,
  ATTRIBUTE_Honest,
  ATTRIBUTE_Deceitful
};

/**
   * @brief Get the string representation of a personality attribute
   * @param attribute The attribute to get the string for.
   */
std::string Get_attribute_string(const Attribute attribute);

}  // namespace his_gen

#endif // HISTORY_GENERATOR_DEFS_H
