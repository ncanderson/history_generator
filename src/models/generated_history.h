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
   * Usings
   */
  using Entity_relationships = std::map<boost::uuids::uuid, std::shared_ptr<his_gen::Entity_relationship>>;

  /**
   * Getters and Setters
   */
  /**
   * @brief Set_entity_relationships
   * @param relationships
   */
  void Set_entity_relationships(const Entity_relationships& relationships) { m_entity_relationships = relationships; }
  Entity_relationships& Get_entity_relationships() { return m_entity_relationships; }
  const Entity_relationships& Get_entity_relationships() const { return m_entity_relationships; }

  /**
   * @brief Add_entity_relationship
   * @param id
   * @param relationship
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
  std::map<boost::uuids::uuid, std::shared_ptr<his_gen::Entity_relationship>> m_entity_relationships;

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
