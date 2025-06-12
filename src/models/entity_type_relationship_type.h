/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_TYPE_RELATIONSHIP_TYPE_H
#define ENTITY_TYPE_RELATIONSHIP_TYPE_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <models/entity_type.h>
#include <models/relationship_type.h>

namespace his_gen
{
/**
 * @brief Relationships allowed between two entities of a given type
 */
class Entity_type_relationship_type
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Default constructor, required for JSON serialization
   */
  Entity_type_relationship_type() = default;

  /**
   * @brief String constructor
   * @param entity_type Entity type name in string format
   * @param relationship_type Relationship type name in string format
   */
  Entity_type_relationship_type(const std::string& entity_type,
                                const std::string& relationship_type);

  /**
   * @brief Enum constructor
   * @param entity_type Enumerated entity type
   * @param relationship_type Enumerated relationship type
   */
  Entity_type_relationship_type(const his_gen::EEntity_type& eentity_type,
                                const his_gen::ERelationship_type& erelationship_type);

  /**
   * @brief Destructor
   */
  ~Entity_type_relationship_type(){};

  /**
   * Getters and setters
   */
  void Set_entity_type(const his_gen::EEntity_type& entity_type) { m_entity_type = entity_type; }
  his_gen::EEntity_type Get_entity_type() const { return m_entity_type; }

  void Set_entity_type_string(const std::string& entity_type_string) { m_entity_type_string = entity_type_string; }
  std::string Get_entity_type_string() const { return m_entity_type_string; }

  void Set_relationship_type(const his_gen::ERelationship_type& relationship_type) { m_relationship_type = relationship_type; }
  his_gen::ERelationship_type Get_relationship_type() const { return m_relationship_type; }

  void Set_relationship_type_string(const std::string& relationship_type_string) { m_relationship_type_string = relationship_type_string; }
  std::string Get_relationship_type_string() const { return m_relationship_type_string; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation
  /**
   * @brief Entity type for this relationship
   */
  his_gen::EEntity_type m_entity_type;

  /**
   * @brief String representation of the entity type
   */
  std::string m_entity_type_string;

  /**
   * @brief Relationship type for this relationship
   */
  his_gen::ERelationship_type m_relationship_type;

  /**
   * @brief String representation of the relationship type
   */
  std::string m_relationship_type_string;

}; // class Entity_type_relationship_type

void to_json(nlohmann::json& json,
             const his_gen::Entity_type_relationship_type& entity_type_relationship_type);

void from_json(const nlohmann::json& json,
               his_gen::Entity_type_relationship_type& entity_type_relationship_type);

}  // namespace his_gen

#endif // ENTITY_TYPE_RELATIONSHIP_TYPE_H
