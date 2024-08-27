/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DATA_ACCESS_DAO_PG_H
#define DATA_ACCESS_DAO_PG_H

// Application files
#include <data_access/data_access_dao_base.h>
#include <defs/history_generator_defs.h>

namespace his_gen
{
/**
 * @brief The Data_access_dao_sql class
 */
class Data_access_dao_pg : public Data_access_dao_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Data_access_dao_pg(const DAL_PG_params& params);

  /**
   * @brief Destructor
   */
  ~Data_access_dao_pg(){};

  /**
   * @brief Create an entity
   */
  void Create_entity();

  /**
   * @brief Simple function to test this DAO class
   */
  void Test_write();

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Data_access_dao_pg
}  // namespace his_gen

#endif // DATA_ACCESS_DAO_PG_H
