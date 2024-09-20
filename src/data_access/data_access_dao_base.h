/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DATA_ACCESS_DAO_BASE_H
#define DATA_ACCESS_DAO_BASE_H

// Standard libraries

// Applicationfiles

// Models
#include <models/generated_history.h>
#include <models/data_definitions.h>

namespace his_gen
{
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
   * @return
   */
  virtual his_gen::Data_definitions Load_data_definitions() = 0;

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
