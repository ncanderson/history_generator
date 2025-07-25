/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

// Standard libs
#include <vector>
#include <memory>
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <defs/history_generator_defs.h>
#include <models/entities/entity_base.h>

// TODO Think a bit more about how this class manages the entities that it cares
// about. Only the ID is being deserialized in the from_json function, meaning
// that any events loaded from file/db will require an additional lookup to
// fully populate the pointer to that entity. In practice this might not matter,
// but if that becomes a requirement, more attention will be required.

namespace his_gen
{
/**
 * @brief The base class for all event types
 */
class Event_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Default constructor
   */
  Event_base() = default;

  /**
   * @brief Explicit constructor to prevent implicit instantiation
   * @param name Name of the event
   */
  explicit Event_base(const std::string& name);

  /**
   * @brief Destructor
   */
  virtual ~Event_base() = default;

  /**
   * Getters and setters
   */
  const std::string& Get_name() const { return m_name; }
  void Set_name(const std::string& name) { m_name = name; }

  his_gen::EEvent_type Get_event_type() const { return m_event_type; }
  void Set_event_type(const his_gen::EEvent_type& event_type) { m_event_type = event_type; }

  std::shared_ptr<Entity_base> Get_triggering_entity() const { return m_triggering_entity; }
  void Set_triggering_entity(const std::shared_ptr<Entity_base>& entity)
  {
    m_triggering_entity = entity;
    m_triggering_entity_id = entity->Get_entity_id();
  }

  const boost::uuids::uuid Get_triggering_entity_id() const {return m_triggering_entity_id; }
  void Set_triggering_entity_id(const boost::uuids::uuid& triggering_entity_id) { m_triggering_entity_id = triggering_entity_id; }

  const std::vector<std::shared_ptr<Entity_base>>& Get_targets() const { return m_targets; }
  // TODO Make these setters also populate the target ID structure
  void Set_targets(const std::vector<std::shared_ptr<Entity_base>>& targets) { m_targets = targets; }
  void Add_target(const std::shared_ptr<Entity_base>& target) { m_targets.push_back(target); }

  const std::vector<boost::uuids::uuid>& Get_target_ids() const { return m_target_ids; }
  void Set_target_ids(const std::vector<boost::uuids::uuid>& target_ids) { m_target_ids = target_ids; }
  void Add_target_id(const boost::uuids::uuid& target_id) { m_target_ids.push_back(target_id); }

  bool Is_complete() const { return m_is_complete; }
  void Set_is_complete(bool complete) { m_is_complete = complete; }


protected:
  // Attributes

  // Implementation
  /**
   * @brief Event initialization function to be overriden by child classes
   */
  virtual void initialize_event() = 0;

  /**
   * @brief Event execution function to be overriden by child classes
   */
  virtual void run_event() = 0;

  /**
   * @brief Event wrap-up function to be overriden by child classes
   */
  virtual void conclude_event() = 0;

  /**
   * @brief Get any follow-on events to schedule
   * @return A vector of unique_ptrs to newly created Event_base instances
   */
  virtual std::vector<std::unique_ptr<Event_base>> get_next_steps() const = 0;

private:
  // Attributes
  /**
   * @brief m_name
   */
  std::string m_name;

  /**
   * @brief m_event_type
   */
  his_gen::EEvent_type m_event_type;

  /**
   * @brief m_triggering_entity
   */
  std::shared_ptr<Entity_base> m_triggering_entity{nullptr};

  /**
   * @brief ID of the triggering entity, used for deserialization
   */
  boost::uuids::uuid m_triggering_entity_id;

  /**
   * @brief Targets of this event
   */
  std::vector<std::shared_ptr<Entity_base>> m_targets;

  /**
   * @brief IDs of this event's targets
   */
  std::vector<boost::uuids::uuid> m_target_ids;

  /**
   * @brief m_is_complete
   */
  bool m_is_complete{false};

  // Implementation

};  // class Event_base

/**
 * @brief JSON serializer, marked inline to keep this virtual base class
 * header-only
 * @param json
 * @param entity_base
 */
inline void to_json(nlohmann::json& json, const his_gen::Event_base& event_base)
{
  json = nlohmann::json
  {
    {"name", event_base.Get_name()},
    {"event_type", event_base.Get_event_type()},
    {"triggering_entity", event_base.Get_triggering_entity()},
    {"triggering_entity_id", event_base.Get_triggering_entity()->Get_entity_id()},
    {"targets", event_base.Get_targets()},
    {"target_ids", event_base.Get_target_ids()},
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
inline void from_json(const nlohmann::json& json, his_gen::Event_base& event_base)
{
  event_base.Set_name(json.at("name"));
  event_base.Set_event_type(json.at("event_type"));
  event_base.Set_triggering_entity_id(json.at("triggering_entity_id"));
  event_base.Set_target_ids(json.at("target_ids"));
  event_base.Set_is_complete(json.at("is_complete"));
}

}  // namespace his_gen


/**
 * @brief By extending the adl_serializer to utilize this class, we can register
 * derived classed allowing us to serialize those classes to JSON
 */
namespace nlohmann
{
template <>
struct adl_serializer<his_gen::Event_base>
  :
  Polymorphic_serializer<his_gen::Event_base>{ };

} // namespace nlohmann

#endif // EVENT_TYPE_H
