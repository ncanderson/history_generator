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
class Data_access_dao_pg : public virtual Data_access_dao_base
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
  ~Data_access_dao_pg() override;

  /**
   * @brief Write history to the DAO object
   * @param generated_history The generated history object
   */
  void Write_history(std::shared_ptr<models::Generated_history> generated_history) override;

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Data_access_dao_pg
}  // namespace his_gen

#endif // DATA_ACCESS_DAO_PG_H
