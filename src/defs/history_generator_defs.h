/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORY_GENERATOR_DEFS_H
#define HISTORY_GENERATOR_DEFS_H

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

}  // namespace his_gen

#endif // HISTORY_GENERATOR_DEFS_H
