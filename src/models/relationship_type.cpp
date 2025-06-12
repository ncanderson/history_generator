/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/relationship_type.h>

///////////////////////////////////////////////////////////////////////

his_gen::Relationship_type::Relationship_type(const std::string& name)
  :
  m_name(name),
  m_relationship_type(his_gen::Get_relationship_type(m_name))
{

}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Relationship_type& relationship_type)
{
  json = nlohmann::json
  {
    {"name", relationship_type.Name},
    {"relationship_type", his_gen::Get_relationship_type_string(relationship_type.Get_relationship_type())}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Relationship_type& relationship_type)
{
  relationship_type.Set_name(his_gen::To_lowercase(json.at("name")));
  relationship_type.Set_relationship_type(his_gen::Get_relationship_type(relationship_type.Get_name()));
}

///////////////////////////////////////////////////////////////////////
