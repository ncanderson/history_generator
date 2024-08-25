/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_H
#define ENTITY_H

// Standard libs
#include <string>

// Application files
#include <utils/history_generator_utils.h>

namespace models
{
/**
 * @brief The Data_access_dao_file class
 */
class Entity
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Entity(std::string entity_name)
    :
      m_name(entity_name)
  {
    his_gen::Print_to_cout(m_name);
  }

  /**
   * @brief Destructor
   */
  ~Entity() {};

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Entity name
   */
  std::string m_name;

  // Implementation

}; // class Entity
}  // namespace models

#endif // ENTITY_H
