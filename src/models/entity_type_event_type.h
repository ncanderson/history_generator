/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_TYPE_EVENT_TYPE_H
#define ENTITY_TYPE_EVENT_TYPE_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <models/entity_type.h>
#include <models/event_type.h>

namespace his_gen
{
/**
 * @brief Events allowed to occur to an entity of a given type
 */
class Entity_type_event_type
{
public:
  // Constructors

  /**
   * @brief Default constructor, required for JSON serialization
   */
  Entity_type_event_type() = default;

  /**
   * @brief String constructor
   * @param entity_type Entity type name in string format
   * @param event_type Event type name in string format
   */
  Entity_type_event_type(const std::string& entity_type,
                         const std::string& event_type);

  /**
   * @brief Enum constructor
   * @param entity_type Enumerated entity type
   * @param event_type Enumerated event type
   */
  Entity_type_event_type(const his_gen::EEntity_type& entity_type,
                         const his_gen::EEvent_type& event_type);

  /**
   * @brief Destructor
   */
  ~Entity_type_event_type() = default;

  // Getters and setters
  void Set_entity_type(const his_gen::EEntity_type& entity_type) { m_entity_type = entity_type; }
  his_gen::EEntity_type Get_entity_type() const { return m_entity_type; }

  void Set_entity_type_string(const std::string& entity_type_string) { m_entity_type_string = entity_type_string; }
  std::string Get_entity_type_string() const { return m_entity_type_string; }

  void Set_event_type(const his_gen::EEvent_type& event_type) { m_event_type = event_type; }
  his_gen::EEvent_type Get_event_type() const { return m_event_type; }

  void Set_event_type_string(const std::string& event_type_string) { m_event_type_string = event_type_string; }
  std::string Get_event_type_string() const { return m_event_type_string; }

private:
  // Attributes

  /**
   * @brief Entity type for this event permission
   */
  his_gen::EEntity_type m_entity_type;

  /**
   * @brief String representation of the entity type
   */
  std::string m_entity_type_string;

  /**
   * @brief Event type allowed for the entity
   */
  his_gen::EEvent_type m_event_type;

  /**
   * @brief String representation of the event type
   */
  std::string m_event_type_string;

}; // class Entity_type_event_type

void to_json(nlohmann::json& json,
             const his_gen::Entity_type_event_type& entity_type_event_type);

void from_json(const nlohmann::json& json,
               his_gen::Entity_type_event_type& entity_type_event_type);

}  // namespace his_gen

#endif // ENTITY_TYPE_EVENT_TYPE_H
