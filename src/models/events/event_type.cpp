/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/event_type.h>

///////////////////////////////////////////////////////////////////////

his_gen::Event_type::Event_type(const std::string& name)
  :
  m_name(name),
  m_event_type(his_gen::Get_event_type(m_name))
{

}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Event_type& event_type)
{
  json = nlohmann::json
  {
    {"name", event_type.Get_name()},
    {"event_type", his_gen::Get_event_type_string(event_type.Get_event_type())}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Event_type& event_type)
{
  event_type.Set_name(his_gen::To_lowercase(json.at("name")));
  event_type.Set_event_type(his_gen::Get_event_type(event_type.Get_name()));
}

///////////////////////////////////////////////////////////////////////
