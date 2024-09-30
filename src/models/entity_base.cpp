/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <models/entity_base.h>

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json, const his_gen::Entity_base& entity_base)
{
  json = nlohmann::json
  {
    {"name", entity_base.Get_name()},
    {"title", entity_base.Get_title()}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json, his_gen::Entity_base& entity_base)
{
  {
    entity_base.Set_name(json.at("name"));
    entity_base.Set_title(json.at("title"));
  }
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
