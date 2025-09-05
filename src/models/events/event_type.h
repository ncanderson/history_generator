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
  EEVENT_TYPE_Courtship,
  EEVENT_TYPE_Elopement,
  EEVENT_TYPE_Marriage,
  EEVENT_TYPE_Reproduce,
  EEVENT_TYPE_Secret_affair,
  EEVENT_TYPE_Seek_partner,
  EEVENT_TYPE_Social_scandal,
  EEVENT_TYPE_Toxic_relationship,
  EEVENT_TYPE_Count
};

/**
 * @brief Lookup table mapping all enumerated event types to their appropriate string
 * representations.
 */
constexpr std::array<Enum_mapping<EEvent_type>,
                     static_cast<size_t>(EEvent_type::EEVENT_TYPE_Count)> event_type_lookup = {
  Enum_mapping{EEvent_type::EEVENT_TYPE_Courtship,           "courtship"},
  Enum_mapping{EEvent_type::EEVENT_TYPE_Elopement,           "elopement"},
  Enum_mapping{EEvent_type::EEVENT_TYPE_Marriage,            "marriage"},
  Enum_mapping{EEvent_type::EEVENT_TYPE_Reproduce,           "reproduce"},
  Enum_mapping{EEvent_type::EEVENT_TYPE_Secret_affair,       "secret_affair"},
  Enum_mapping{EEvent_type::EEVENT_TYPE_Seek_partner,        "seek_partner"},
  Enum_mapping{EEvent_type::EEVENT_TYPE_Social_scandal,      "social_scandal"},
  Enum_mapping{EEvent_type::EEVENT_TYPE_Toxic_relationship,  "toxic_relationship"}
};

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
