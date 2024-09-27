/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entity_sentient.h>

// Defs
#include <defs/json_helper_defs.h>

///////////////////////////////////////////////////////////////////////

his_gen::Entity_sentient::Entity_sentient(std::string name,
                                          std::string title,
                                          bool test)
    :
    Entity_base(name, title),
    m_personality()
{
  // Register the derived class with the JSON serializer
  Polymorphic_serializer<his_gen::Entity_base>::register_types<his_gen::Entity_base,
                                                               his_gen::Entity_sentient>();
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_sentient& entity_sentient)
{
  nlohmann::to_json(json, static_cast<Entity_base>(entity_sentient));
  json.update(
  {
    {"personality", "test"}//entity_sentient.Get_personality()}
  });
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_sentient& entity_sentient)
{
  entity_sentient.Set_name(json.at("name"));
  entity_sentient.Set_title(json.at("title"));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
