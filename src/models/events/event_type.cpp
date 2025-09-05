/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/event_type.h>

///////////////////////////////////////////////////////////////////////

his_gen::Event_type::Event_type(const his_gen::EEvent_type& event_type)
    :
    m_name(his_gen::Get_event_type_string(event_type)),
    m_event_type(event_type)
{ }

///////////////////////////////////////////////////////////////////////

// Namespace member, not class member
std::string his_gen::Get_event_type_string(const EEvent_type& event_type)
{
  switch (event_type)
  {
    case EEVENT_TYPE_Courtship:    return "courtship";
    case EEVENT_TYPE_Reproduce:    return "reproduce";
    case EEVENT_TYPE_Seek_partner: return "seek_partner";
    case EEVENT_TYPE_Elopement,
    case EEVENT_TYPE_Marriage,
    case EEVENT_TYPE_Secret_affair,
    case EEVENT_TYPE_Social_scandal,
    case EEVENT_TYPE_Toxic_relationship,
    default:
      throw std::invalid_argument("Event type not found");
  }
}

///////////////////////////////////////////////////////////////////////

// Namespace member, not class member
his_gen::EEvent_type his_gen::Get_event_type(const std::string& event_type)
{
  static const std::unordered_map<std::string, EEvent_type> event_type_map = {
      {"courtship",    EEVENT_TYPE_Courtship},
      {"reproduce",    EEVENT_TYPE_Reproduce},
      {"seek_partner", EEVENT_TYPE_Seek_partner}
  };

  const std::string lc_event_type = his_gen::To_lowercase(event_type);

  auto it = event_type_map.find(lc_event_type);
  if(it != event_type_map.end())
  {
    return it->second;
  }
  else
  {
    his_gen::Print_to_cout(lc_event_type);
    throw std::invalid_argument("Can't find event type from string");
  }
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
  // NOOP
  // The attrs are currently private, so this may not ever be required
}

///////////////////////////////////////////////////////////////////////
