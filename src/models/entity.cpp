/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entity.h>

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity& entity)
{
  json = nlohmann::json
  {
    {"name", entity.Name}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                   his_gen::Entity& entity)
{
  json.at("name").get_to(entity.Name);
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
