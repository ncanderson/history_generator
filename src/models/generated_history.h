/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef GENERATED_HISTORY_H
#define GENERATED_HISTORY_H

// Standard libs

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

  // Implementation
  /**
   * @brief Constructor
   */
  Generated_history();

  /**
   * @brief Destructor
   */
  ~Generated_history(){};

  /**
   * Simple Getters and Setters
   */
  void Set_entity_relationships(const Entity_relationships& relationships) { m_entity_relationships = relationships; }
  Entity_relationships& Get_entity_relationships() { return m_entity_relationships; }
  // Extra getter to facilitate JSON serialization
  const Entity_relationships& Get_entity_relationships() const { return m_entity_relationships; }

  void Set_entities(const Entities& entities) { m_entities = entities; }
  Entities& Get_entities() { return m_entities; }
  // Extra getter to facilitate JSON serialization
  const Entities& Get_entities() const { return m_entities; }

  void Set_events(const Events& events) { m_events = events; }
  Events& Get_events() { return m_events; }
  // Extra getter to facilitate JSON serialization
  const Events& Get_events() const { return m_events; }

  // TODO Refactor these into templates, as we're doing the same logic on different containers
  /**
   * More Complex Getters and Setters
   */

  /**
   * @brief Add_entity_relationship
   * @param id ID of the entity relationship
   * @param relationship The object maintaining the relationship
   */
  void Add_entity_relationship(const boost::uuids::uuid& id,
                               const std::shared_ptr<his_gen::Entity_relationship>& relationship)
  {
    m_entity_relationships[id] = relationship;
  }

  /**
   * @brief Get_entity_relationship
   * @param id ID of the Entity relationship to return
   * @return The Entity_relationship object
   * @throws std::out_of_range Thrown if the sought ID isn't found
   */
  std::shared_ptr<his_gen::Entity_relationship> Get_entity_relationship(const boost::uuids::uuid& id) const
  {
      auto it = m_entity_relationships.find(id);
      if (it == m_entity_relationships.end())
      {
        throw std::out_of_range("Entity relationship not found for given UUID");
      }
      return it->second;
  }

  /**
   * @brief Add_entity
   * @param id
   * @param entity
   */
  void Add_entity(const boost::uuids::uuid& id,
                  const std::shared_ptr<his_gen::Entity_base>& entity)
  {
    m_entities[id] = entity;
  }

  /**
   * @brief Get_entity
   * @param id ID of the Entity to return
   * @return The entity pointer
   * @throws std::out_of_range Thrown if the sought ID isn't found
   */
  std::shared_ptr<his_gen::Entity_base> Get_entity(const boost::uuids::uuid& id) const
  {
    auto it = m_entities.find(id);
    if (it == m_entities.end())
    {
      throw std::out_of_range("Entity not found for given UUID");
    }
    return it->second;
  }

  /**
   * @brief Add_event
   * @param id
   * @param event
   */
  void Add_event(const boost::uuids::uuid& id,
                 const std::shared_ptr<his_gen::Event_base>& event)
  {
    m_events[id] = event;
  }

  /**
   * @brief Get_event
   * @param id ID of the Event to return
   * @return The event pointer
   * @throws std::out_of_range Thrown if the sought ID isn't found
   */
  std::shared_ptr<his_gen::Event_base> Get_event(const boost::uuids::uuid& id) const
  {
    auto it = m_events.find(id);
    if (it == m_events.end())
    {
      throw std::out_of_range("Event not found for given UUID");
    }
    return it->second;
  }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief List of all entity relationships
   * @details A map holding an ID key to an Entity_relationship instance. The key should be stored
   * in the relationship IDs map of the entity this relationship is owned by.
   */
  Entity_relationships m_entity_relationships;

  /**
   * @brief List of all generated entities.
   * @details A map holding an ID key to an Entity_base instance. The key is stored on the entity,
   * and can be used for lookup in this structure.
   */
  Entities m_entities;

  /**
   * @brief List of all generated events.
   * @details A map holding an ID key to an Event_base instance. The key is stored on the event,
   * and can be used for lookup in this structure.
   */
  Events m_events;

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
