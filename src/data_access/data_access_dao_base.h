/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DATA_ACCESS_DAO_BASE_H
#define DATA_ACCESS_DAO_BASE_H

// Standard libraries

// Applicationfiles

// Models
#include <models/generated_history.h>

namespace his_gen
{
/**
 * @brief The Data_access_type enum
 * @details Determine the type of data source we'll be accessing
 */
enum Data_access_type
{
  DATA_ACCESS_TYPE_Unknown,   ///< Unknown data access type
  DATA_ACCESS_TYPE_File,      ///< File
  DATA_ACCESS_TYPE_Postgres,  ///< PostgreSQL database
  DATA_ACCESS_TYPE_Count      ///< Count
};

/**
 * @brief Lookup table mapping all enumerated data access types to their appropriate string
 * representations.
 */
constexpr std::array<Enum_mapping<Data_access_type>,
                     static_cast<size_t>(Data_access_type::DATA_ACCESS_TYPE_Count)> data_access_type_lookup = {
  Enum_mapping{Data_access_type::DATA_ACCESS_TYPE_Unknown,  "unknown"},
  Enum_mapping{Data_access_type::DATA_ACCESS_TYPE_File,     "file"},
  Enum_mapping{Data_access_type::DATA_ACCESS_TYPE_Postgres, "postgres"}
};

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

/**
 * @brief The Data_access_dao_base class
 */
class Data_access_dao_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Destructor
   */
  virtual ~Data_access_dao_base(){};

  /**
   * @brief Write history to the DAO object
   * @param generated_history The generated history object
   */
  virtual void Write_history(his_gen::Generated_history& generated_history) = 0;

  /**
   * @brief Load_data_definitions
   */
  virtual void Load_data_definitions() = 0;

  /**
   * @brief Load_all_names
   * @param names
   * @param titles
   */
  virtual void Load_all_names(std::vector<std::string>& names,
                              std::vector<std::string>& titles) = 0;

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Data_access_dao_base
}  // namespace his_gen

#endif // DATA_ACCESS_DAO_BASE_H
