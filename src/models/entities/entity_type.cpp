/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entities/entity_type.h>

///////////////////////////////////////////////////////////////////////

his_gen::Entity_type::Entity_type(const his_gen::EEntity_type& entity_type)
  :
  m_name(his_gen::Enum_to_string(entity_type, entity_type_lookup)),
  m_entity_type(entity_type)
{ }

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_type& entity_type)
{
  json = nlohmann::json
  {
    {"name", entity_type.Get_name()},
    {"entity_type", his_gen::Enum_to_string(entity_type.Get_entity_type(),
                                            entity_type_lookup)}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_type& entity_type)
{
  // NOOP
  // The attrs are currently private, and this may not ever be required
}

///////////////////////////////////////////////////////////////////////
