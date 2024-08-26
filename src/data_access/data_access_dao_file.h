/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DATA_ACCESS_DAO_FILE_H
#define DATA_ACCESS_DAO_FILE_H

// Application files
#include <data_access/data_access_dao_base.h>

namespace his_gen
{
/**
 * @brief The Data_access_dao_file class
 */
class Data_access_dao_file : public Data_access_dao_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Data_access_dao_file()
    :
      Data_access_dao_base()
  {

  }

  /**
   * @brief Destructor
   */
  ~Data_access_dao_file();

  /**
   * @brief Create an entity
   */
  void Create_entity();

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Data_access_dao_base
}  // namespace his_gen

#endif // DATA_ACCESS_DAO_FILE_H