/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entity_base.h>

// test
#include <models/entity_sentient.h>
//

///////////////////////////////////////////////////////////////////////

his_gen::Entity_base::Entity_base(std::string name, std::string title)
    :
    m_name(name),
    m_title(title)
{
};

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

void his_gen::to_json(nlohmann::json& json, const std::shared_ptr<his_gen::Entity_base>& entity_base)
{
  json = nlohmann::json
  {
    {"name", entity_base->Get_name()},
    {"title", entity_base->Get_title()}
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
