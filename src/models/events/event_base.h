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
  void Set_triggering_entity(const std::shared_ptr<Entity_base>& entity) { m_triggering_entity = entity; }

  const std::vector<std::shared_ptr<Entity_base>>& Get_targets() const { return m_targets; }
  void Set_targets(const std::vector<std::shared_ptr<Entity_base>>& targets) { m_targets = targets; }
  void Add_target(const std::shared_ptr<Entity_base>& target) { m_targets.push_back(target); }

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
   * @brief m_targets
   */
  std::vector<std::shared_ptr<Entity_base>> m_targets;

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
    {"targets", event_base.Get_targets()},
    {"is_complete", event_base.Is_complete()},
  };
}

/**
 * @brief JSON de-serializer, marked inline to keep this virtual base class
 * header-only
 * @param json
 * @param entity_base
 */
inline void from_json(const nlohmann::json& json, his_gen::Event_base& event_base)
{
  {
    event_base.Set_name(json.at("name"));
    event_base.Set_event_type(json.at("event_type"));
    event_base.Set_triggering_entity(json.at("triggering_entity"));
    event_base.Set_targets(json.at("targets"));
    event_base.Set_is_complete(json.at("is_complete"));
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
struct adl_serializer<his_gen::Event_base>
  :
  Polymorphic_serializer<his_gen::Event_base>{ };

} // namespace nlohmann

#endif // EVENT_TYPE_H
