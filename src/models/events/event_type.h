/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

// Standard libs

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <defs/history_generator_defs.h>

namespace his_gen
{
/**
 * @brief The type of event
 */
class Event_type
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Default constructor, required for JSON serialization
   */
  Event_type() = default;

  /**
   * @brief Constructor
   */
  Event_type(const std::string& name);

  /**
   * @brief Destructor
   */
  ~Event_type(){};

  /**
   * Getters and setters
   */
  void Set_name(const std::string& name) { m_name = name; }
  std::string Get_name() const { return m_name; }

  void Set_event_type(const his_gen::EEvent_type& eevent_type) { m_event_type = eevent_type; }
  his_gen::EEvent_type Get_event_type() const { return m_event_type; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Entity type name
   */
  std::string m_name;

  /**
   * @brief Enumerated event type
   */
  his_gen::EEvent_type m_event_type;

  // Implementation

}; // class Entity_type

void to_json(nlohmann::json& json,
             const his_gen::Event_type& event_type);

void from_json(const nlohmann::json& json,
               his_gen::Event_type& event_type);

}  // namespace his_gen

#endif // EVENT_TYPE_H
