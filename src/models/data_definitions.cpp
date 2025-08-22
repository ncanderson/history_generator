/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard

// 3rd Party
#include <deps/magic_enum.hpp>

// Application Files
#include <models/data_definitions.h>
#include <utils/dice_rolls.h>

///////////////////////////////////////////////////////////////////////

his_gen::Data_definitions::Data_definitions()
  :
  Entity_type_relationship_types(),
  Entity_type_event_types(),
  Entity_types(),
  Relationship_types(),
  Event_types(),
  m_entity_events(),
  m_entity_relationships()
{
  // Populate data members from enums
  initialize_members_from_enums();
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_definitions::Initialize_composite_data()
{
  build_entity_relationships(Entity_type_relationship_types);
  build_entity_events(Entity_type_event_types);
}

///////////////////////////////////////////////////////////////////////

his_gen::EEntity_type his_gen::Data_definitions::Get_rand_entity_type()
{
  return his_gen::dice::Get_random_element(Entity_types).Get_entity_type();
}

///////////////////////////////////////////////////////////////////////

his_gen::EEvent_type his_gen::Data_definitions::Get_rand_entity_event(his_gen::EEntity_type entity)
{
  return his_gen::dice::Get_random_element(m_entity_events[entity]);
}

///////////////////////////////////////////////////////////////////////

his_gen::ERelationship_type his_gen::Data_definitions::Get_rand_entity_relationship(his_gen::EEntity_type entity)
{
  return his_gen::dice::Get_random_element(m_entity_relationships[entity]);
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_definitions::build_entity_events(const std::vector<his_gen::Entity_type_event_type>& ent_event)
{
  for(auto& it : ent_event)
  {
    m_entity_events[it.Get_entity_type()].push_back(it.Get_event_type());
  }
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_definitions::build_entity_relationships(const std::vector<his_gen::Entity_type_relationship_type>& ent_rel)
{
  for(auto& it : ent_rel)
  {
    m_entity_relationships[it.Get_entity_type()].push_back(it.Get_relationship_type());
  }
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_definitions::initialize_members_from_enums()
{
  // Populate Entity_types from all enum values
  Entity_types.clear();
  for (auto e : magic_enum::enum_values<his_gen::EEntity_type>())
  {
    Entity_type ent_type = Entity_type(his_gen::Get_entity_type_string(e));
    Entity_types.push_back(ent_type);
  }

  // Populate Relationship_types from all enum values
  Relationship_types.clear();
  for (auto r : magic_enum::enum_values<his_gen::ERelationship_type>())
  {
    Relationship_type rel_type = Relationship_type(his_gen::Get_relationship_type_string(r));
    Relationship_types.push_back(rel_type);
  }

  // Populate Event_types from all enum values
  Event_types.clear();
  for (auto ev : magic_enum::enum_values<his_gen::EEvent_type>()) {
    Event_type evt_type = Event_type(his_gen::Get_event_type_string(ev));
    Event_types.push_back(evt_type);
  }
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Data_definitions& data_definitions)
{
  json = nlohmann::json
  {
    {"entity_type_relationship_types", data_definitions.Entity_type_relationship_types},
    {"entity_type_event_types", data_definitions.Entity_type_event_types},
    {"entity_types", data_definitions.Entity_types},
    {"relationship_type", data_definitions.Relationship_types},
    {"event_types", data_definitions.Event_types}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Data_definitions& data_definitions)
{
  json.at("entity_type_relationship_types").get_to(data_definitions.Entity_type_relationship_types);
  json.at("entity_type_event_types").get_to(data_definitions.Entity_type_event_types);

  data_definitions.Initialize_composite_data();
}

///////////////////////////////////////////////////////////////////////
// END OF FILE

