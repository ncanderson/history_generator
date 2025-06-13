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
   * @brief Constructor
   */
  Entity_relationship(boost::uuids::uuid relationship_id,
                      std::shared_ptr<his_gen::Entity_base> entity_1,
                      std::shared_ptr<his_gen::Entity_base> entity_2);

  /**
   * @brief Destructor
   */
  ~Entity_relationship(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief The ID for this relationship
   * @details This ID will be used by any entity that has a relationship to track
   */
  boost::uuids::uuid m_relationship_id;

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

void to_json(nlohmann::json& json,
             const his_gen::Entity_relationship& entity_relationship);

void from_json(const nlohmann::json& json,
               his_gen::Entity_relationship& entity_relationship);

}  // namespace his_gen

#endif // ENTITY_RELATIONSHIP_H
