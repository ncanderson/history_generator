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
 * @brief The data definitions used by all generators
 * @details This class uses only static, private data members. All instance methods
 * operate on these static members. This allows a single shared set of
 * definitions throughout the application
 */
class Data_definitions
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor deleted to prevent instantiation
   */
  Data_definitions() = delete;

  /**
   * @brief Destructor deleted to prevent instantiation
   */
  ~Data_definitions() = delete;

  /**
   * @brief Additional initialization steps beyond the deserialization
   * of any loaded JSON values
   */
  static void Initialize();

  /**
   * @brief Return a random entity type
   */
  static his_gen::EEntity_type Get_rand_entity_type();

  /**
   * @brief Return a random valid event for this entity type
   * @param entity The entity to get an event for
   * @return A random valid event type
   */
  static his_gen::EEvent_type Get_rand_entity_event(const his_gen::EEntity_type& entity);

  /**
   * @brief Return a random valid relationship for this entity type
   * @param entity The entity to get a relationship for
   * @return A random valid relationship type
   */
  static his_gen::ERelationship_type Get_rand_entity_relationship(const his_gen::EEntity_type& entity);

  /**
   * Getters and Setters
   */
  static const std::vector<his_gen::Entity_type_relationship_type>& Get_entity_type_relationship_types() { return s_entity_type_relationship_types; }
  static const std::vector<his_gen::Entity_type_event_type>& Get_entity_type_event_types() { return s_entity_type_event_types; }
  static const std::vector<his_gen::Entity_type>& Get_entity_types() { return s_entity_types; }
  static const std::vector<his_gen::Relationship_type>& Get_relationship_types() { return s_relationship_types; }
  static const std::vector<his_gen::Event_type>& Get_event_types() { return s_event_types; }

  static const std::map<his_gen::EEntity_type, std::vector<his_gen::ERelationship_type>>& Get_entity_relationships() { return s_entity_relationships; }
  static const std::vector<his_gen::ERelationship_type>& Get_entity_relationships(const his_gen::EEntity_type& entity_type) { return s_entity_relationships[entity_type]; }
  static const std::map<his_gen::EEntity_type, std::vector<his_gen::EEvent_type>>& Get_entity_events() { return s_entity_events; }
  static const std::vector<his_gen::EEvent_type>& Get_entity_events(const his_gen::EEntity_type& entity_type) { return s_entity_events[entity_type]; }

  static void Set_entity_type_relationship_types(const std::vector<his_gen::Entity_type_relationship_type>& v) { s_entity_type_relationship_types = v; }
  static void Set_entity_type_event_types(const std::vector<his_gen::Entity_type_event_type>& v) { s_entity_type_event_types = v; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief List of all possible entity relationship types based on entity type
   */
  static std::vector<his_gen::Entity_type_relationship_type> s_entity_type_relationship_types;

  /**
   * @brief List of all possible entity event types based on entity type
   */
  static std::vector<his_gen::Entity_type_event_type> s_entity_type_event_types;

  /**
   * @brief List of all entity types
   */
  static std::vector<his_gen::Entity_type> s_entity_types;

  /**
   * @brief List of all entity relationship types
   */
  static std::vector<his_gen::Relationship_type> s_relationship_types;

  /**
   * @brief List of all event types
   */
  static std::vector<his_gen::Event_type> s_event_types;

  /**
   * @brief Map of entity type/event type pairs, re-ordered to facilitate
   * retrieval from outside this class.
   */
  static std::map<his_gen::EEntity_type, std::vector<his_gen::EEvent_type>> s_entity_events;

  /**
   * @brief Map of entity type/relationship type pairs, re-ordered to facilitate
   * retrieval from outside this class.
   */
  static std::map<his_gen::EEntity_type, std::vector<his_gen::ERelationship_type>> s_entity_relationships;

  // Implementation
  /**
   * @brief Populate the static entity/event map from external data
   * @param ent_event A vector of entity type/event type pairs
   */
  static void build_entity_events(const std::vector<his_gen::Entity_type_event_type>& ent_event);

  /**
   * @brief Populate the static entity/relationship map from external data
   * @param ent_rel A vector of entity type/relationship type pairs
   */
  static void build_entity_relationships(const std::vector<his_gen::Entity_type_relationship_type>& ent_rel);

  /**
   * @brief Helper function to set up the static vectors of basic data types
   */
  static void initialize_members_from_enums();

}; // class Data_definitions

/**
 * @brief to_json
 * @param json
 * @param data_definitions
 */
void to_json(nlohmann::json& json,
             const his_gen::Data_definitions& data_definitions);

}  // namespace his_gen

#endif // DATA_DEFINITIONS_H
