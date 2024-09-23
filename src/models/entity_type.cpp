/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entity_type.h>

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_type& entity_type)
{
  json = nlohmann::json
  {
    {"name", entity_type.Get_name()}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_type& entity_type)
{
  entity_type.Set_name(json.at("name"));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
