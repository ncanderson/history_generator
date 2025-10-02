/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef EVENT_BASE_H
#define EVENT_BASE_H

// Standard libs
#include <vector>
#include <memory>
#include <string>
#include <unordered_set>

// 3rd party
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/random_generator.hpp>
#include <deps/json.hpp>

// Application files
#include <defs/history_generator_aliases.h>
#include <defs/history_generator_defs.h>
#include <defs/json_helper_defs.h>

#include <models/data_definitions.h>
#include <models/generated_history.h>
#include <models/event_visitor.h>

#include <utils/history_generator_utils.h>

namespace his_gen
{
/**
 * @brief Forward declaration of Event_scheduler
 */
class Event_scheduler;

/**
 * @brief The base class for all event types
 * @details Implementing class should call meaningful_change_occurred() to indicate
 * if the event should be saved. If follow-up events are necessary, schedule_next_event()
 * should be called to ensure that event will be triggered during the next
 * event tick.
 */
class Event_base : public Event_visitor
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Event_base
   * @param event_type
   * @param triggering_entity_id
   * @param current_tick
   * @param triggering_event_id
   */
  Event_base(const his_gen::EEvent_type event_type,
             const boost::uuids::uuid& triggering_entity_id,
             const uint64_t current_tick,
             const boost::uuids::uuid triggering_event_id = boost::uuids::nil_uuid())
    :
    m_event_id(boost::uuids::random_generator()()),
    m_event_tick(current_tick),
    m_event_type(event_type),
    m_name(his_gen::Enum_to_string(event_type, event_type_lookup)),
    m_triggering_entity_id(triggering_entity_id),
    m_triggering_event_id(triggering_event_id),
    m_target_ids(),
    m_relationship_ids(),
    m_is_complete(false),
    m_event_changes_state(false)
  { }

  /**
   * @brief Destructor
   */
  virtual ~Event_base() = default;

  /**
   * @brief Run the event. Implementing functions will determine
   * what 'Run' means.
   * @details By default, the value of `m_event_changes_state` will be used
   * to determine if this event has created meaningful change that should be saved
   * @param history_of_the_world The current `Generated_history` object
   * @param event_scheduler Object to track upcoming events that result from this event
   */
  virtual void Run(his_gen::Generated_history& history_of_the_world,
                   Event_scheduler& event_scheduler) = 0;

  /**
   * @brief If true, this event created meaningful change and should be saved.
   * @details Implementing classes can override this function if different save logic
   * is required
   * @return
   */
  virtual bool Created_meaningful_change() const { return m_event_changes_state; }

  /**
   * @brief Return the derived class's list of possible next events
   * @details The data type returned from this function isn't declared as a
   * data member in this base class; derived classes are expected to define
   * an unordered set of possible next evets for return by this function.
   * @return An unordered set of the possible next events
   */
  virtual const std::unordered_set<his_gen::EEvent_type>& Get_possible_next_events() const = 0;

  /////////////////////////////////////////////////
  // Getters and setters

  boost::uuids::uuid Get_event_id() const { return m_event_id; }
  void Set_event_id(const boost::uuids::uuid& event_id) { m_event_id = event_id; }

  int64_t Get_event_tick() const { return m_event_tick; }
  void Set_event_tick(const int64_t event_tick) { m_event_tick = event_tick; }

  his_gen::EEvent_type Get_event_type() const { return m_event_type; }
  void Set_event_type(const his_gen::EEvent_type& event_type) { m_event_type = event_type; }

  const std::string& Get_name() const { return m_name; }
  void Set_name(const std::string& name) { m_name = name; }

  const boost::uuids::uuid Get_triggering_entity_id() const {return m_triggering_entity_id; }
  void Set_triggering_entity_id(const boost::uuids::uuid& triggering_entity_id) { m_triggering_entity_id = triggering_entity_id; }

  const boost::uuids::uuid Get_triggering_event_id() const {return m_triggering_event_id; }
  void Set_triggering_event_id(const boost::uuids::uuid& triggering_event_id) { m_triggering_event_id = triggering_event_id; }

  const std::vector<boost::uuids::uuid>& Get_target_ids() const { return m_target_ids; }
  void Set_target_ids(const std::vector<boost::uuids::uuid>& target_ids) { m_target_ids = target_ids; }
  void Add_target_id(const boost::uuids::uuid& target_id) { m_target_ids.push_back(target_id); }

  const std::vector<boost::uuids::uuid>& Get_relationship_ids() const { return m_relationship_ids; }
  void Set_relationship_ids(const std::vector<boost::uuids::uuid>& relationship_ids) { m_relationship_ids = relationship_ids; }
  void Add_relationship_id(const boost::uuids::uuid& relationship_id) { m_relationship_ids.push_back(relationship_id); }

  bool Is_complete() const { return m_is_complete; }
  void Set_is_complete(bool complete) { m_is_complete = complete; }

protected:
  // Attributes
  /**
   * @brief ID of this event
   */
  boost::uuids::uuid m_event_id;

  /**
   * @brief The current generation tick
   */
  uint64_t m_event_tick;

  /**
   * @brief m_event_type
   */
  his_gen::EEvent_type m_event_type;

  /**
   * @brief m_name
   */
  std::string m_name;

  /**
   * @brief ID of the triggering entity, used for deserialization
   */
  boost::uuids::uuid m_triggering_entity_id;

  /**
   * @brief ID of the triggering event, if applicable
   */
  boost::uuids::uuid m_triggering_event_id;

  /**
   * @brief Entity IDs of this event's targets
   */
  std::vector<boost::uuids::uuid> m_target_ids;

  /**
   * @brief IDs for any relationships created or modified by this event
   * @details Since some event chains have the potential to modify relationships
   * established in prior events, this vector will allow scheduled events
   * to find and modify the relationships that are changed.
   */
  std::vector<boost::uuids::uuid> m_relationship_ids;

  /**
   * @brief m_is_complete
   */
  bool m_is_complete;

  /**
   * @brief If true, this event has created meaningful change and should be saved
   */
  bool m_event_changes_state;

  // Implementation
  /**
   * @brief Schedule the next event
   * @param event_scheduler The event scheduler instance to use for scheduling
   */
  virtual void schedule_next_event(Event_scheduler& event_scheduler) = 0;

  /**
   * @brief Helper function to clarify this classes interface.
   * @details If necessary, derived classes can override this function. By default
   * this function will set the variable that will be checked externally to
   * determine if this event should be saved.
   * @param change_occurred This event created meaningful change
   */
  virtual void meaningful_change_occurred(bool change_occurred) { m_event_changes_state = change_occurred; }

  /**
   * @brief Using the entity IDs stored on this event, get the pointer to the entity
   * @param entities The full entity map
   * @return The extracted target entities
   */
  virtual std::vector<std::shared_ptr<his_gen::Entity_base>> get_target_entities(his_gen::Entities& entities)
  {
    // The target ID(s) of this event
    std::vector<boost::uuids::uuid> target_ids = Get_target_ids();
    // Pull those entities out of the main strucutre to isolate them for simplicity
    std::vector<std::shared_ptr<his_gen::Entity_base>> target_entities;
    for(auto& it : target_ids)
    {
      target_entities.push_back(entities[it]);
    }
    return target_entities;
  }

private:
  // Attributes

  // Implementation

};

/**
 * @brief JSON serializer, marked inline to keep this virtual base class
 * header-only
 * @param json
 * @param entity_base
 */
inline void to_json(nlohmann::json& json,
                    const his_gen::Event_base& event_base)
{
  json = nlohmann::json
  {
    {"event_id", event_base.Get_event_id()},
    {"type", his_gen::Enum_to_string(event_base.Get_event_type(), event_type_lookup)},
    {"event_tick", event_base.Get_event_tick()},
    {"triggering_entity_id", event_base.Get_triggering_entity_id()},
    {"triggering_event_id", event_base.Get_triggering_event_id()},
    {"target_ids", event_base.Get_target_ids()},
    {"relationship_ids", event_base.Get_relationship_ids()},
    {"is_complete", event_base.Is_complete()},
  };
}

/**
 * @brief JSON de-serializer, marked inline to keep this virtual base class
 * header-only
 * @details For simplicity, this from_json function doesn't deserialize an entire
 * entity, but rather uses just the ID. Allowing full deserialization of derived
 * classes could be performed later, but will require additional extension of
 * the adl_serializer
 * @param json
 * @param entity_base
 */
inline void from_json(const nlohmann::json& json,
                      his_gen::Event_base& event_base)
{
  event_base.Set_event_id(json.at("event_id"));
  event_base.Set_name(json.at("name"));
  // This has to be called after name, unless we want to write an adl deserializer
  // for a string view, which we don't
  event_base.Set_event_type(his_gen::String_to_enum(event_base.Get_name(), event_type_lookup));
  event_base.Set_event_tick(json.at("event_tick"));
  event_base.Set_triggering_entity_id(json.at("triggering_entity_id"));
  event_base.Set_triggering_event_id(json.at("triggering_event_id"));
  event_base.Set_target_ids(json.at("target_ids"));
  event_base.Set_relationship_ids(json.at("relationship_ids"));
  event_base.Set_is_complete(json.at("is_complete"));
}

} // namespace his_gen

/**
 * @brief By extending the adl_serializer to utilize this class, we can register
 * derived classed allowing us to serialize those classes to JSON
 */
namespace nlohmann
{

/**
 * @brief Initialize Event_base for registration with derived classes
 */
template <>
struct adl_serializer<his_gen::Event_base>
  :
  Polymorphic_serializer<his_gen::Event_base>
{ };

} // namespace nlohmann

#endif
