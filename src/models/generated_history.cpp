/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs

// JSON

// Application files
#include <models/generated_history.h>

// Models
#include <models/entities/entity_base.h>
#include <models/events/event_base.h>
#include <models/relations/entity_relationship.h>

///////////////////////////////////////////////////////////////////////

his_gen::Generated_history::Generated_history()
  :
  m_entity_relationships(),
  m_entities(),
  m_events()
{ }

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Generated_history& generated_history)
{
  json = nlohmann::json
  {
    {"entities", generated_history.Get_entities()},
    {"events", generated_history.Get_events()},
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
