/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef NAMES_H
#define NAMES_H

// Standard libs
#include <string>

// Application files
#include <data_access/data_access_manager.h>

namespace his_gen
{
/**
 * @brief Static (non-instantiable) Names module.
 * @details
 */
class Names
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Initialize the data for this class to make it available statically
   * @param data_access_manager The object that will provide the names data
   */
  static void Initialize(const his_gen::Data_access_manager& data_access_manager);

  /**
   * @brief Get one name
   * @return A single name
   */
  static std::string Get_one_name();

  /**
   * @brief Get one title
   * @return A single title
   */
  static std::string Get_one_title();

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief List of names
   */
  static std::vector<std::string> m_names;

  /**
   * @brief List of titles
   */
  static std::vector<std::string> m_titles;

  // Implementation
  /**
   * @brief Delete constructor to prevent instantiation
   */
  Names() = delete;

}; // class Names
}  // namespace his_gen

#endif // NAMES_H
