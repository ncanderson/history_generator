/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entities/entity_type.h>

///////////////////////////////////////////////////////////////////////

his_gen::Entity_type::Entity_type(const std::string& name)
  :
  m_name(name),
  m_entity_type(his_gen::Get_entity_type(m_name))
{

}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_type& entity_type)
{
  json = nlohmann::json
  {
    {"name", entity_type.Get_name()},
    {"entity_type", his_gen::Get_entity_type_string(entity_type.Get_entity_type())}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_type& entity_type)
{
  entity_type.Set_name(his_gen::To_lowercase(json.at("name")));
  entity_type.Set_entity_type(his_gen::Get_entity_type(entity_type.Get_name()));
}

///////////////////////////////////////////////////////////////////////
