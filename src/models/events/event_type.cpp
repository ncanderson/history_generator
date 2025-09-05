/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/event_type.h>

///////////////////////////////////////////////////////////////////////

his_gen::Event_type::Event_type(const his_gen::EEvent_type& event_type)
    :
    m_name(his_gen::Enum_to_string(event_type, event_type_lookup)),
    m_event_type(event_type)
{ }

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Event_type& event_type)
{
  json = nlohmann::json
  {
    {"name", event_type.Get_name()},
    {"event_type", his_gen::Enum_to_string(event_type.Get_event_type(), event_type_lookup)}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Event_type& event_type)
{
  // NOOP
  // The attrs are currently private, so this may not ever be required
}

///////////////////////////////////////////////////////////////////////
