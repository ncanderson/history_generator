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
   * @brief List of all generated entities.
   * @details This vector will hold any entity derived from entity base.
   */
  std::vector<std::shared_ptr<his_gen::Entity_base>> Entities;

  /**
   * @brief List of all entity relationships
   */
  std::vector<his_gen::Entity_relationship> Entity_relationships;

  // Implementation
  /**
   * @brief Constructor
   */
  Generated_history()
    :
      Entities(),
      Entity_relationships()
  {
  }

  /**
   * @brief Destructor
   */
  ~Generated_history(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Generated_history

/**
 * @brief to_json
 * @param json
 * @param generated_history
 */
void to_json(nlohmann::json& json,
             const his_gen::Generated_history& generated_history);

/**
 * @brief from_json
 * @param json
 * @param generated_history
 */
void from_json(const nlohmann::json& json,
               his_gen::Generated_history& generated_history);

}  // namespace his_gen

#endif // GENERATED_HISTORY_H
