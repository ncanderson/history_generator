/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entity.h>

///////////////////////////////////////////////////////////////////////

his_gen::Entity::Entity(std::string name,
                        std::string title)
    :
    Entity_base(name, title)
{
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity& entity)
{
  json = nlohmann::json
  {
    {"name", entity.Get_name()},
    {"title", entity.Get_title()}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                   his_gen::Entity& entity)
{
  entity.Set_name(json.at("name"));
  entity.Set_title(json.at("title"));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
