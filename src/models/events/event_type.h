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
 * @brief Enumerates all general event types used in the historical simulation.
 */
enum EEvent_type
{
  EEVENT_TYPE_Courtship,          ///< Further a relationship, determine where it goes
  EEVENT_TYPE_Elopement,          ///<
  EEVENT_TYPE_Marriage,           ///<
  EEVENT_TYPE_Reproduce,          ///< Create a new entity
  EEVENT_TYPE_Secret_affair,      ///<
  EEVENT_TYPE_Seek_partner,       ///< Seek a partner, romatic or otherwise
  EEVENT_TYPE_Social_scandal,     ///<
  EEVENT_TYPE_Toxic_relationship  ///<
};

/**
 * @brief Get the string representation of an EEvent_type.
 * @param event_type The event type enum value.
 * @return Lowercase string form (e.g. "died", "formed_alliance").
 */
std::string Get_event_type_string(const EEvent_type& event_type);

/**
 * @brief Convert a string to its corresponding EEvent_type enum value.
 * @param event_type The string to convert (case-insensitive).
 * @return Matching enum value.
 * @throws std::invalid_argument Thrown if no match is found.
 */
EEvent_type Get_event_type(const std::string& event_type);

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
   * @param event_type The event type to instantiate
   */
  Event_type(const his_gen::EEvent_type& event_type);

  /**
   * @brief Destructor
   */
  ~Event_type(){};

  /**
   * Getters and setters
   */
  std::string Get_name() const { return m_name; }
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

/**
 * @brief to_json
 * @param json
 * @param event_type
 */
void to_json(nlohmann::json& json,
             const his_gen::Event_type& event_type);

/**
 * @brief from_json
 * @param json
 * @param event_type
 */
void from_json(const nlohmann::json& json,
               his_gen::Event_type& event_type);

}  // namespace his_gen

#endif
