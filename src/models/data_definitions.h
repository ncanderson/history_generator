/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DATA_DEFINITIONS_H
#define DATA_DEFINITIONS_H

// Standard libs

// JSON
#include <deps/json.hpp>

// Models
#include <models/entity_type_relationship_type.h>
#include <models/entity_type.h>
#include <models/relationship_type.h>

namespace his_gen
{
/**
 * @brief A generated entity
 */
class Data_definitions
{
public:
  // Attributes
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
  Data_definitions();

  /**
   * @brief Destructor
   */
  ~Data_definitions(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Data_definitions

/**
 * @brief to_json
 * @param json
 * @param data_definitions
 */
void to_json(nlohmann::json& json, const
             his_gen::Data_definitions& data_definitions);

/**
 * @brief from_json
 * @param json
 * @param data_definitions
 */
void from_json(const nlohmann::json& json,
               his_gen::Data_definitions& data_definitions);

}  // namespace his_gen

#endif // DATA_DEFINITIONS_H
