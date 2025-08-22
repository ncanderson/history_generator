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
  //Entity_base() = default;

  /**
   * @brief Entity_base
   * @param name
   * @param entity_type
   * @param current_tick
   * @param title
   */
  Entity_base(const std::string& name,
              const EEntity_type entity_type,
              const uint64_t current_tick,
              const std::string& title = "")
    :
    m_entity_id(boost::uuids::random_generator()()),
    m_entity_type(entity_type),
    m_entity_relationship_ids(),
    m_name(name),
    m_title(title),
    m_creation_tick(current_tick),
    m_last_event_triggered(0)
  { }

  /**
   * @brief Virtual destructor.
   */
  virtual ~Entity_base() = default;

  /**
   * @brief Perform any necessary object initialization steps.
   * @details As the entity classes will be part of polymorphic inheritance trees,
   * it may be necessary for a derived class to perform instantiation steps,
   * and the compiler will complain if calling a base class virtual member
   * on a derived instance. By calling `Initialize()` from a factory, all necessary
   * initialization steps can be performed after instantiation and the desired
   * function will be called.
   */
  virtual void Initialize() = 0;

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
  const boost::uuids::uuid Get_entity_id() const { return m_entity_id; }
  void Set_entity_id(const boost::uuids::uuid& entity_id) { m_entity_id = entity_id; }

  const EEntity_type Get_entity_type() const { return m_entity_type; }
  void Set_entity_type(const EEntity_type& entity_type) { m_entity_type = entity_type; }

  const std::string Get_name() const { return m_name; }
  void Set_name(const std::string& name) { m_name = name; }

  const std::string Get_title() const { return m_title; }
  void Set_title(const std::string& title) { m_title=title; }

  const std::vector<boost::uuids::uuid> Get_relationship_ids() const { return m_entity_relationship_ids; }
  void Set_relationship_ids(const std::vector<boost::uuids::uuid>& entity_relationship_ids) { m_entity_relationship_ids = entity_relationship_ids; }
  void Add_relationship_id(const boost::uuids::uuid& relationship_id) { m_entity_relationship_ids.push_back(relationship_id); }

  const uint64_t Get_creation_tick() const { return m_creation_tick; }
  void Set_creation_tick(const uint64_t tick) { m_creation_tick = tick; }

  const uint64_t Get_last_event_triggered() const { return m_last_event_triggered; }
  void Set_last_event_triggered(const uint64_t tick) { m_last_event_triggered = tick; }

protected:
  // Attributes
  /**
   * @brief ID of this entity
   */
  boost::uuids::uuid m_entity_id;

  /**
   * @brief Enumerated type of this entity
   */
  EEntity_type m_entity_type;

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

  /**
   * @brief The current generation tick
   */
  uint64_t m_creation_tick;

  /**
   * @brief Last tick this entity triggered an event
   */
  uint64_t m_last_event_triggered;

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
    {"id", entity_base.Get_entity_id()},
    {"entity_type", his_gen::Get_entity_type_string(entity_base.Get_entity_type())},
    {"name", entity_base.Get_name()},
    {"title", entity_base.Get_title()},
    {"relationship_ids", entity_base.Get_relationship_ids()},
    {"creation_tick", entity_base.Get_creation_tick()}
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
  entity_base.Set_entity_id(json.at("id"));
  entity_base.Set_entity_type(his_gen::Get_entity_type(json.at("entity_type")));
  entity_base.Set_name(json.at("name"));
  entity_base.Set_title(json.at("title"));
  entity_base.Set_relationship_ids(json.at("relationship_ids"));
  entity_base.Set_creation_tick(json.at("creation_tick"));
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
