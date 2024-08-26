/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DATA_ACCESS_MANAGER_H
#define DATA_ACCESS_MANAGER_H

// Standard libraries
#include <memory>

// Application files
#include <data_access/data_access_dao_base.h>
#include <defs/history_generator_defs.h>

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
  /**
   * @brief Constructor for a file-based data acces layer
   * @param params Parameters for a file connection
   */
  Data_access_manager(const his_gen::DAL_file_params& params);

  /**
   * @brief Constructor for a PostgreSQL-based data acces layer
   * @param params Parameters for a PostgreSQL database connection
   */
  Data_access_manager(const his_gen::DAL_PG_params& params);

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
