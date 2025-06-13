/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/relations/entity_type_relationship_type.h>

using et_rt = his_gen::Entity_type_relationship_type;

///////////////////////////////////////////////////////////////////////

et_rt::Entity_type_relationship_type(const std::string& entity_type,
                                     const std::string& relationship_type)
  :
  m_entity_type_string(entity_type),
  m_entity_type(his_gen::Get_entity_type(entity_type)),
  m_relationship_type_string(relationship_type),
  m_relationship_type(his_gen::Get_relationship_type(entity_type))
{

}

///////////////////////////////////////////////////////////////////////

et_rt::Entity_type_relationship_type(const his_gen::EEntity_type& eentity_type,
                                     const his_gen::ERelationship_type& erelationship_type)
  :
  m_entity_type(eentity_type),
  m_entity_type_string(his_gen::Get_entity_type_string(eentity_type)),
  m_relationship_type(erelationship_type),
  m_relationship_type_string(his_gen::Get_relationship_type_string(erelationship_type))
{

}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_type_relationship_type& entity_type_relationship_type)
{
  json = nlohmann::json
  {
    {"entity_type", entity_type_relationship_type.Get_entity_type()},
    {"relationship_type", entity_type_relationship_type.Get_relationship_type()}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_type_relationship_type& entity_type_relationship_type)
{
  entity_type_relationship_type.Set_entity_type_string(his_gen::To_lowercase(json.at("entity_type")));
  entity_type_relationship_type.Set_entity_type(his_gen::Get_entity_type(entity_type_relationship_type.Get_entity_type_string()));
  entity_type_relationship_type.Set_relationship_type_string(his_gen::To_lowercase(json.at("relationship_type")));
  entity_type_relationship_type.Set_relationship_type(his_gen::Get_relationship_type(entity_type_relationship_type.Get_relationship_type_string()));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
