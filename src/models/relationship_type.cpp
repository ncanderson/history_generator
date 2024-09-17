/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/relationship_type.h>

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Relationship_type& relationship_type)
{
  json = nlohmann::json
  {
    {"name", relationship_type.Name}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Relationship_type& relationship_type)
{
  json.at("name").get_to(relationship_type.Name);
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
