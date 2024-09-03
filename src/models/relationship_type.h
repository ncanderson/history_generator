/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef RELATIONSHIP_TYPE_H
#define RELATIONSHIP_TYPE_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>

namespace models
{
/**
 * @brief The type of relationship between entities
 */
class Relationship_type
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Relationship_type(){}

  /**
   * @brief Destructor
   */
  ~Relationship_type() {};  

  /**
   * @brief Write relationship type object to JSON
   * @param json Pointer to the json we'll be writing to
   * @param entity The relationship type to write
   */
  void To_json(nlohmann::json& json,
               std::shared_ptr<Relationship_type> relationship_type);

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Relationship_type
}  // namespace models

#endif // RELATIONSHIP_TYPE_H
