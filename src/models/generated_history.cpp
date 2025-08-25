/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/generated_history.h>

///////////////////////////////////////////////////////////////////////

his_gen::Generated_history::Generated_history()
  :
  Entities(),
  Events(),
  m_entity_relationships()
{ }

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Generated_history& generated_history)
{
  json = nlohmann::json
  {
    {"entities", generated_history.Entities},
    {"events", generated_history.Events},
    {"entity_relationships", generated_history.Get_entity_relationships()}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Generated_history& generated_history)
{
  auto json_history = json.template get<his_gen::Generated_history>();
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
