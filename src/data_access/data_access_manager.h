/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DATA_ACCESS_MANAGER_H
#define DATA_ACCESS_MANAGER_H

// Standard libraries
#include <memory>

// Application files
#include <data_access/data_access_dao_base.h>

namespace his_gen
{
/**
 * @brief Data access layer manager
 * @details Class that manages data source connections
 */
class Data_access_manager
{
public:
  // Attributes

  // Implementation
  Data_access_manager(){}

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  std::shared_ptr<his_gen::Data_access_dao_base> m_txport;

  // Implementation

}; // class Data_access_manager
}  // namespace his_gen

#endif // DATA_ACCESS_MANAGER_H
