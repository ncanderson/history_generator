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
#include <models/entities/entity_type.h>
#include <models/events/event_base.h>
#include <models/relations/entity_relationship.h>
#include <models/relations/entity_type_relationship_type.h>
#include <models/relationships/relationship_type.h>

namespace his_gen
{
/**
 * @brief The 'master' data type to contain vectors of all generated history
 */
class Generated_history
{
public:
  // Attributes
  /**
   * @brief List of all generated entities.
   * @details This vector will hold any objects derived from the base class
   */
  std::vector<std::shared_ptr<his_gen::Entity_base>> Entities;

  /**
   * @brief List of all generated events.
   * @details This vector will hold any objects derived from the base class
   */
  std::vector<std::shared_ptr<his_gen::Event_base>> Events;

  /**
   * @brief List of all entity relationships
   * @details This vector will hold all entity relationships,
   */
  std::map<boost::uuids::uuid, std::shared_ptr<his_gen::Entity_relationship>> Entity_relationships;

  // Implementation
  /**
   * @brief Constructor
   */
  Generated_history();

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
