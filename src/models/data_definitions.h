/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DATA_DEFINITIONS_H
#define DATA_DEFINITIONS_H

// Standard libs

// JSON
#include <deps/json.hpp>

// Models
#include <models/relations/entity_type_relationship_type.h>
#include <models/relations/entity_type_event_type.h>
#include <models//entities/entity_type.h>
#include <models/relationships/relationship_type.h>
#include <models/events/event_type.h>

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
   * @brief List of all possible entity event types based on entity type
   */
  std::vector<his_gen::Entity_type_event_type> Entity_type_event_types;

  /**
   * @brief List of all entity types
   */
  std::vector<his_gen::Entity_type> Entity_types;

  /**
   * @brief List of all entity relationship types
   */
  std::vector<his_gen::Relationship_type> Relationship_types;

  /**
   * @brief Event_types
   */
  std::vector<his_gen::Event_type> Event_types;

  // Implementation
  /**
   * @brief Constructor
   */
  Data_definitions();

  /**
   * @brief Destructor
   */
  ~Data_definitions(){};

  /**
   * @brief When instantiated directly from JSON, this class won't necessarily
   * have full acccess to all data in the constructor. This function allows
   * the class to fully initialize any data members not fully constructible
   * from JSON.
   */
  void Initialize_composite_data();

  /**
   * @brief Return a random entity type
   */
  his_gen::EEntity_type Get_rand_entity_type();

  /**
   * @brief Return a random valid event for this entity type
   * @param entity The entity to get an event for
   * @return A random valid event type
   */
  his_gen::EEvent_type Get_rand_entity_event(his_gen::EEntity_type entity);

  /**
   * @brief Return a random valid relationship for this entity type
   * @param entity The entity to get a relationship for
   * @return A random valid relationship type
   */
  his_gen::ERelationship_type Get_rand_entity_relationship(his_gen::EEntity_type entity);

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Map of entity type/event type pairs, re-ordered to facilitate
   * retrieval from outside this class.
   */
  std::map<his_gen::EEntity_type, std::vector<his_gen::EEvent_type>> m_entity_events;

  /**
   * @brief Map of entity type/relationship type pairs, re-ordered to facilitate
   * retrieval from outside this class.
   */
  std::map<his_gen::EEntity_type, std::vector<his_gen::ERelationship_type>> m_entity_relationships;

  // Implementation
  /**
   * @brief Populate the local map from external data
   * @param ent_event A map of entity types as a key, with the corresponding
   * event types as a value.
   */
  void build_entity_events(const std::vector<his_gen::Entity_type_event_type>& ent_event);

  /**
   * @brief Populate the local map from external data
   * @param ent_rel A map of entity types as a key, with the corresponding
   * relationship types as a value.
   */
  void build_entity_relationships(const std::vector<his_gen::Entity_type_relationship_type>& ent_rel);

}; // class Data_definitions

/**
 * @brief to_json
 * @param json
 * @param data_definitions
 */
void to_json(nlohmann::json& json,
             const his_gen::Data_definitions& data_definitions);

/**
 * @brief from_json
 * @param json
 * @param data_definitions
 */
void from_json(const nlohmann::json& json,
               his_gen::Data_definitions& data_definitions);

}  // namespace his_gen

#endif // DATA_DEFINITIONS_H
