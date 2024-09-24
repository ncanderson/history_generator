/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entity.h>

///////////////////////////////////////////////////////////////////////

his_gen::Entity_sentient::Entity_sentient(std::string name,
                                          std::string title)
    :
    Entity_base(name, title)
{
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_sentient& entity_sentient)
{
  //void to_json( nlohmann::json& JSON, const B& b ) {
  //  nlohmann::to_json(JSON, static_cast<A>(b));
  //  JSON.update({ {"Ba", b.Ba}, {"Bb", b.Bb} });
  //}

  nlohmann::to_json(json, static_cast<Entity_base>(entity_sentient));
  json.update(
    {
      {"name", entity_sentient.Get_name()},
      {"title", entity_sentient.Get_title()}
    });
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                   his_gen::Entity_sentient& entity_sentient)
{
  //void from_json( const nlohmann::json& JSON, B& b ) {
  //  nlohmann::from_json(JSON, static_cast<A&>(b));
  //  JSON.at("Ba").get_to(b.Ba);
  //  JSON.at("Bb").get_to(b.Bb);
  //}

  entity_sentient.Set_name(json.at("name"));
  entity_sentient.Set_title(json.at("title"));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
