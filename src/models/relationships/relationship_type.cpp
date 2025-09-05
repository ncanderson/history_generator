/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/relationships/relationship_type.h>

///////////////////////////////////////////////////////////////////////

his_gen::Relationship_type::Relationship_type(const his_gen::ERelationship_type& relationship_type)
  :
  m_name(his_gen::Enum_to_string(relationship_type, relationship_type_lookup)),
  m_relationship_type(relationship_type)
{ }

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Relationship_type& relationship_type)
{
  json = nlohmann::json
  {
    {"name", relationship_type.Get_name()},
    {"relationship_type", his_gen::Enum_to_string(relationship_type.Get_relationship_type(),
                                                  relationship_type_lookup)}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Relationship_type& relationship_type)
{
  // NOOP
  // The attrs are currently private, and this may not ever be required
}

///////////////////////////////////////////////////////////////////////
