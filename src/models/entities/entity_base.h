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
#include <models/data_definitions.h>

namespace his_gen
{

/**
 * Forward declaration allowing usage of the Event_visitor class,
 * itself providing events access to entity-specific behaviors.
 */
class Event_visitor;

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
    m_last_event_triggered(0),
    m_max_events_by_type(initialize_events_maps()),
    m_count_events_by_type(initialize_events_maps()),
    m_default_max_event_type(1)
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
   * @brief The argued event type is valid for this entity
   * @details Implementing classes should use this function to impose any necessary limits
   * on triggered events. For example, a god might maintain 20 lovers but refuse to marry,
   * or a particularly peaceful nation may never go to war. This function is implemented
   * at the entity level since different entities will have different limits based
   * on attributes.
   * @param event_type The event type to check
   * @param current_tick The current generation tick, compared to the last time this entity
   * has had an event of any type triggered.
   * @return True if the event type is valid, otherwise false
   */
  virtual bool Event_is_valid(his_gen::EEvent_type event_type,
                              uint8_t current_tick)
  {
    // The entity has not had an event this tick, and this entity's event count
    // does not exceed its max allowable value
    return current_tick > m_last_event_triggered &&
           get_events_count(event_type) < get_max_events(event_type);
  }

  /**
   * @brief Increment the count of this entity's events
   * @details This function allows anything that interacts with this entity
   * to let it know that a new event has been created for it.
   * @param event_type The event type to check
   * @param value The value to increment by, defaulting to 1
   */
  void Increment_events_count(his_gen::EEvent_type event_type, uint16_t value = 1)
  {
    // If missing, insert with 0, then add value
    m_count_events_by_type[event_type] += value;
  }

  /**
   * @brief Helper function allowing events the ability to call functions
   * from derived entities.
   * @param visitor An Event_visitor instance that bridges specific derived
   * class functionality between events and entities.
   */
  virtual void Accept_event(his_gen::Event_visitor& visitor) = 0;

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

  /**
   * @brief The maximum number of events of each type for this entity
   */
  std::map<his_gen::EEvent_type, uint16_t> m_max_events_by_type;

  /**
   * @brief The number of events for this entity, by type
   */
  std::map<his_gen::EEvent_type, uint16_t> m_count_events_by_type;

  /**
   * @brief Start value for max event type
   */
  uint8_t m_default_max_event_type;

  // Implementation
  /**
   * @brief Use this entity's attributes to populate the 'max events'
   * map.
   * @details The base class function will default all values to 1; implementing classes
   * can and should refine their own max values.
   */
  virtual void initialize_max_events_by_type() = 0;

  /**
   * @brief get_default_max_event_type
   * @return The default max event type
   */
  uint8_t get_default_max_event_type() const { return m_default_max_event_type; }

  /**
   * @brief Get max event count by type
   * @param event_type The event type to return
   * @return The max count
   */
  uint16_t get_max_events(his_gen::EEvent_type event_type) const
  {
    auto it = m_max_events_by_type.find(event_type);
    if (it == m_max_events_by_type.end())
    {
      throw std::out_of_range(std::string(his_gen::Enum_to_string(event_type, event_type_lookup)) +
                              " not found in max events map");
    }
    return it->second;
  }

  /**
   * @brief Set the max event count by type
   * @param event_type The event type to check
   * @param value The max count
   */
  void set_max_events(his_gen::EEvent_type event_type, uint16_t value)
  {
    m_max_events_by_type[event_type] = value;
  }

  /**
   * @brief Get this entity's current event count by type
   * @param event_type The event type to return
   * @return The entity's current event count of this type
   */
  uint16_t get_events_count(his_gen::EEvent_type event_type) const
  {
    auto it = m_count_events_by_type.find(event_type);
    if (it == m_count_events_by_type.end())
    {
      throw std::out_of_range("Event type not found in count events map");
    }
    return it->second;
  }

private:
  // Attributes

  // Implementation
  /**
   * @brief Initialize the events maps to 0 for this entity
   * @details This function will take all valid events and insert them into the map
   * with a value of 0, for both 'count' and 'max' maps.
   * @return The now constucted events count map
   */
  std::map<his_gen::EEvent_type, uint16_t> initialize_events_maps()
  {
    std::map<his_gen::EEvent_type, uint16_t> initial_counts;
    std::vector<his_gen::Event_type> events = his_gen::Data_definitions::Get_event_types();
    // Loop through all events
    for(const auto& event : events)
    {
      his_gen::EEvent_type event_enum = event.Get_event_type();
      initial_counts[event_enum] = 0;
    }
    return initial_counts;
  }

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
    {"entity_type", his_gen::Enum_to_string(entity_base.Get_entity_type(),
                                              entity_type_lookup)},
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
  entity_base.Set_entity_type(his_gen::String_to_enum(std::string(json.at("entity_type")),
                                                      entity_type_lookup));
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
