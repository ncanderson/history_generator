/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entity_type_relationship_type.h>

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_type_relationship_type& entity_type_relationship_type)
{
  json = nlohmann::json
  {
    {"entity_type", entity_type_relationship_type.Entity_type},
    {"relationship_type", entity_type_relationship_type.Relationship_type}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_type_relationship_type& entity_type_relationship_type)
{
  json.at("entity_type").get_to(entity_type_relationship_type.Entity_type);
  json.at("relationship_type").get_to(entity_type_relationship_type.Relationship_type);
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
