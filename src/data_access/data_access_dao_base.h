/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DATA_ACCESS_DAO_BASE_H
#define DATA_ACCESS_DAO_BASE_H

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
   * @brief Virtual base for entity creation functions
   */
  virtual void Create_entity() = 0;

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Data_access_dao_base
}  // namespace his_gen

#endif // DATA_ACCESS_DAO_BASE_H
