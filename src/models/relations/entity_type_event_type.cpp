/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/relations/entity_type_event_type.h>

using et_et = his_gen::Entity_type_event_type;

///////////////////////////////////////////////////////////////////////

et_et::Entity_type_event_type(const std::string& entity_type,
                              const std::string& event_type)
  :
  m_entity_type_string(entity_type),
  m_entity_type(his_gen::Get_entity_type(entity_type)),
  m_event_type_string(event_type),
  m_event_type(his_gen::String_to_enum(event_type, event_type_lookup))
{

}

///////////////////////////////////////////////////////////////////////

et_et::Entity_type_event_type(const his_gen::EEntity_type& entity_type,
                              const his_gen::EEvent_type& event_type)
  :
  m_entity_type(entity_type),
  m_entity_type_string(his_gen::Get_entity_type_string(entity_type)),
  m_event_type(event_type),
  m_event_type_string(his_gen::Enum_to_string(event_type, event_type_lookup))
{

}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_type_event_type& entity_type_event_type)
{
  json = nlohmann::json
    {
      {"entity_type", entity_type_event_type.Get_entity_type_string()},
      {"event_type", entity_type_event_type.Get_event_type_string()}
    };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_type_event_type& entity_type_event_type)
{
  entity_type_event_type.Set_entity_type_string(his_gen::To_lowercase(json.at("entity_type")));
  entity_type_event_type.Set_entity_type(his_gen::Get_entity_type(entity_type_event_type.Get_entity_type_string()));

  entity_type_event_type.Set_event_type_string(his_gen::To_lowercase(json.at("event_type")));
  entity_type_event_type.Set_event_type(his_gen::String_to_enum(entity_type_event_type.Get_event_type_string(),
                                                                event_type_lookup));
}

///////////////////////////////////////////////////////////////////////
