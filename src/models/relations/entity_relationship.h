/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_RELATIONSHIP_H
#define ENTITY_RELATIONSHIP_H

// Standard libs
#include <boost/uuid/random_generator.hpp>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <models/entities/entity_base.h>
#include <models/relationships/relationship_type.h>

namespace his_gen
{
/**
 * @brief The relationship between two entities
 */
class Entity_relationship
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Default constructor, required for JSON serialization
   */
  Entity_relationship() = default;

  /**
   * @brief Entity_relationship
   * @param relationship_id
   * @param relationship_type
   * @param entity_1
   * @param entity_2
   */
  Entity_relationship(const boost::uuids::uuid& relationship_id,
                      const his_gen::Relationship_type& relationship_type,
                      const std::shared_ptr<his_gen::Entity_base>& entity_1,
                      const std::shared_ptr<his_gen::Entity_base>& entity_2);

  /**
   * @brief Destructor
   */
  ~Entity_relationship(){};

  /**
   * Usings
   */
  using Entity_relationship_ptr = std::shared_ptr<his_gen::Entity_relationship>;

  /**
   * @brief Build an entity relationship, assinging all meta-data to the appropriate objects
   * @param entity_1 The primary entity
   * @param entity_2 The target entity
   * @param relationship_type The relationship between each entity
   * @returns The created ID for this entity relationship
   */
  static Entity_relationship_ptr Entity_relationship_factory(std::shared_ptr<his_gen::Entity_base>& entity_1,
                                                             std::shared_ptr<his_gen::Entity_base>& entity_2,
                                                             const his_gen::ERelationship_type& relationship_type);

  /**
   * Getters and setters
   */
  const boost::uuids::uuid& Get_entity_relationship_id() const { return m_entity_relationship_id; }
  const his_gen::Relationship_type& Get_relationship_type() const { return m_relationship_type; }
  const std::shared_ptr<his_gen::Entity_base>& Get_entity_1() const { return m_entity_1; }
  const std::shared_ptr<his_gen::Entity_base>& Get_entity_2() const { return m_entity_2; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief The ID for this relationship
   * @details This ID will be used by any entity that tracks this relationship
   */
  boost::uuids::uuid m_entity_relationship_id;

  /**
   * @brief The type of this relationship
   */
  his_gen::Relationship_type m_relationship_type;

  /**
   * @brief First entity in this relationship
   */
  std::shared_ptr<his_gen::Entity_base> m_entity_1;

  /**
   * @brief Second entity in this relationship
   */
  std::shared_ptr<his_gen::Entity_base> m_entity_2;

  // Implementation

}; // class Entity_relationship

/**
 * @brief to_json
 * @param json
 * @param entity_relationship
 */
void to_json(nlohmann::json& json,
             const his_gen::Entity_relationship& entity_relationship);

/**
 * @brief from_json
 * @param json
 * @param entity_relationship
 */
void from_json(const nlohmann::json& json,
               his_gen::Entity_relationship& entity_relationship);

}  // namespace his_gen

#endif // ENTITY_RELATIONSHIP_H
