/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H

// Standard libs
#include <string>
#include <boost/uuid/random_generator.hpp>

// JSON
#include <deps/json.hpp>
#include <defs/json_helper_defs.h>

// Application files
#include <utils/history_generator_utils.h>

namespace his_gen
{
/**
 * @brief Base class for generated entities
 */
class Entity_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   */
  Entity_base(std::string name, std::string title = "")
    :
    m_entity_relationship_ids(),
    m_name(name),
    m_title(title)
  { }

  /**
   * @brief Virtual destructor.
   */
  virtual ~Entity_base() = default;

  /**
   * @brief Is_attracted to other entity
   * @details This function is provided to allow for single entity comparisons
   * @param other_entity
   * @return True if this entity is attracted to `other_entity`
   */
  virtual bool Is_attracted(std::shared_ptr<Entity_base> other_entity) = 0;

  /**
   * @brief Is_attracted to other_entity
   * @param other_entity The entity to compare to
   * @param attracted_to A vector of entities that this entity is attracted to.
   * This will be used to populate with entities that we'll later check for
   * mutual attraction.
   * @return True if this entity is attracted to `other_entity`
   */
  virtual bool Is_attracted(std::shared_ptr<Entity_base> other_entity,
                            std::vector<std::shared_ptr<Entity_base>> attracted_to) = 0;

  /**
   * Getters and setters
   */
  std::string Get_name() const { return m_name; }
  void Set_name(const std::string& name) { m_name = name; }

  std::string Get_title() const { return m_title; }
  void Set_title(const std::string& title) { m_title=title; }

  std::vector<boost::uuids::uuid> Get_relationship_ids() const { return m_entity_relationship_ids; }
  void Set_relationship_ids(const std::vector<boost::uuids::uuid>& entity_relationship_ids) { m_entity_relationship_ids = entity_relationship_ids; }
  void Add_relationship_id(const boost::uuids::uuid& relationship_id) { m_entity_relationship_ids.push_back(relationship_id); }

protected:
  // Attributes
  /**
   * @brief Vector of this entity's relationships.
   * @details These relationship IDs will be used to access the relationships
   * from the main map of all relationships.
   */
  std::vector<boost::uuids::uuid> m_entity_relationship_ids;

  /**
   * @brief Entity name
   */
  std::string m_name;

  /**
   * @brief Entity title
   */
  std::string m_title;

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Entity_base

/**
 * @brief JSON serializer, marked inline to keep this virtual base class
 * header-only
 * @param json
 * @param entity_base
 */
inline void to_json(nlohmann::json& json, const his_gen::Entity_base& entity_base)
{
  json = nlohmann::json
  {
    {"name", entity_base.Get_name()},
    {"title", entity_base.Get_title()},
    {"relationship_ids", entity_base.Get_relationship_ids()}
  };
}

/**
 * @brief JSON de-serializer, marked inline to keep this virtual base class
 * header-only
 * @param json
 * @param entity_base
 */
inline void from_json(const nlohmann::json& json, his_gen::Entity_base& entity_base)
{
  {
    entity_base.Set_name(json.at("name"));
    entity_base.Set_title(json.at("title"));
    entity_base.Set_relationship_ids(json.at("relationship_ids"));
  }
}

}  // namespace his_gen

/**
 * @brief By extending the adl_serializer to utilize this class, we can register
 * derived classed allowing us to serialize those classes to JSON
 */
namespace nlohmann
{
template <>
struct adl_serializer<his_gen::Entity_base>
    :
    Polymorphic_serializer<his_gen::Entity_base>{ };

} // namespace nlohmann

#endif // ENTITY_BASE_H
