/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entity.h>

///////////////////////////////////////////////////////////////////////

his_gen::Entity::Entity(std::string name,
                        std::string title)
    :
    Name(name),
    Title(title)
{
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity& entity)
{
  json = nlohmann::json
  {
    {"name", entity.Name},
    {"title", entity.Title}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                   his_gen::Entity& entity)
{
  json.at("name").get_to(entity.Name);
  json.at("title").get_to(entity.Title);
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
