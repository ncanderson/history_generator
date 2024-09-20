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
 * @brief Names module
 */
class Names
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Names
   * @param data_access_manager
   */
  Names(const his_gen::Data_access_manager& data_access_manager);

  /**
   * @brief Destructor
   */
  ~Names(){};

  /**
   * @brief Get one name
   * @return A single name
   */
  std::string Get_one_name();

  /**
   * @brief Get one title
   * @return A single title
   */
  std::string Get_one_title();

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Address of data access manager
   */
  const his_gen::Data_access_manager& m_data_access_manager;

  /**
   * @brief List of names
   */
  std::vector<std::string> m_names;

  /**
   * @brief List of titles
   */
  std::vector<std::string> m_titles;

  // Implementation
  /**
   * @brief load_all_names
   * @param names
   * @param titles
   */
  void load_all_names(std::vector<std::string>& names,
                      std::vector<std::string>& titles);

}; // class Names
}  // namespace his_gen

#endif // NAMES_H
