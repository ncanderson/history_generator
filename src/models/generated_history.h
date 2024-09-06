/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef GENERATED_HISTORY_H
#define GENERATED_HISTORY_H

// Standard libs
#include <vector>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>

// Models
#include <models/entity_relationship.h>
#include <models/entity_type_relationship_type.h>
#include <models/entity_type.h>
#include <models/entity.h>
#include <models/relationship_type.h>

namespace his_gen
{
/**
 * @brief The 'master' data type to contain vectors of all generate history
 */
class Generated_history
{
public:
  // Attributes
  /**
   * @brief List of all generated entities
   */
  std::vector<his_gen::Entity> Entities;

  /**
   * @brief List of all entity relationships
   */
  std::vector<his_gen::Entity_relationship> Entity_relationships;

  /**
   * @brief List of all possible entity relationship types based on entity type
   */
  std::vector<his_gen::Entity_type_relationship_type> Entity_type_relationship_types;

  /**
   * @brief List of all entity types
   */
  std::vector<his_gen::Entity_type> Entity_types;

  /**
   * @brief List of all entity relationship types
   */
  std::vector<his_gen::Relationship_type> Relationship_types;

  // Implementation
  /**
   * @brief Constructor
   */
  Generated_history()
    :
      Entities(),
      Entity_relationships(),
      Entity_type_relationship_types(),
      Entity_types(),
      Relationship_types()
  {
  }

  /**
   * @brief Destructor
   */
  ~Generated_history() {};

  /**
   * @brief Write history object to JSON
   * @param json Pointer to the json we'll be writing to
   * @param generated_history The history object to write
   */
  void To_json(nlohmann::json& json,
               std::shared_ptr<Generated_history> generated_history);

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Generated_history
}  // namespace models

#endif // GENERATED_HISTORY_H
