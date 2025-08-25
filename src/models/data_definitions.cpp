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

using dd = his_gen::Data_definitions;

///////////////////////////////////////////////////////////////////////

// Static Member Definitions
std::vector<his_gen::Entity_type_relationship_type> dd::s_entity_type_relationship_types;
std::vector<his_gen::Entity_type_event_type> dd::s_entity_type_event_types;
std::vector<his_gen::Entity_type> dd::s_entity_types;
std::vector<his_gen::Relationship_type> dd::s_relationship_types;
std::vector<his_gen::Event_type> dd::s_event_types;

std::map<his_gen::EEntity_type, std::vector<his_gen::EEvent_type>> dd::s_entity_events;
std::map<his_gen::EEntity_type, std::vector<his_gen::ERelationship_type>> dd::s_entity_relationships;

///////////////////////////////////////////////////////////////////////

dd::Data_definitions()
{
  // Populate static members from enums if empty
  if (s_entity_types.empty())
  {
    initialize_members_from_enums();
  }
}

///////////////////////////////////////////////////////////////////////

void dd::Initialize_composite_data()
{
  build_entity_relationships(s_entity_type_relationship_types);
  build_entity_events(s_entity_type_event_types);
}

///////////////////////////////////////////////////////////////////////

his_gen::EEntity_type dd::Get_rand_entity_type()
{
  return his_gen::dice::Get_random_element(s_entity_types).Get_entity_type();
}

///////////////////////////////////////////////////////////////////////

his_gen::EEvent_type dd::Get_rand_entity_event(his_gen::EEntity_type entity)
{
  return his_gen::dice::Get_random_element(s_entity_events[entity]);
}

///////////////////////////////////////////////////////////////////////

his_gen::ERelationship_type dd::Get_rand_entity_relationship(his_gen::EEntity_type entity)
{
  return his_gen::dice::Get_random_element(s_entity_relationships[entity]);
}

///////////////////////////////////////////////////////////////////////

void dd::build_entity_events(const std::vector<his_gen::Entity_type_event_type>& ent_event)
{
  for (auto& it : ent_event)
  {
    s_entity_events[it.Get_entity_type()].push_back(it.Get_event_type());
  }
}

///////////////////////////////////////////////////////////////////////

void dd::build_entity_relationships(const std::vector<his_gen::Entity_type_relationship_type>& ent_rel)
{
  for (auto& it : ent_rel)
  {
    s_entity_relationships[it.Get_entity_type()].push_back(it.Get_relationship_type());
  }
}

///////////////////////////////////////////////////////////////////////

void dd::initialize_members_from_enums()
{
  // Populate Entity_types from all enum values
  s_entity_types.clear();
  for (auto e : magic_enum::enum_values<his_gen::EEntity_type>())
  {
    Entity_type ent_type = Entity_type(his_gen::Get_entity_type_string(e));
    s_entity_types.push_back(ent_type);
  }

  // Populate Relationship_types from all enum values
  s_relationship_types.clear();
  for (auto r : magic_enum::enum_values<his_gen::ERelationship_type>())
  {
    Relationship_type rel_type = Relationship_type(r);
    s_relationship_types.push_back(rel_type);
  }

  // Populate Event_types from all enum values
  s_event_types.clear();
  for (auto ev : magic_enum::enum_values<his_gen::EEvent_type>())
  {
    Event_type evt_type = Event_type(ev);
    s_event_types.push_back(evt_type);
  }
}

///////////////////////////////////////////////////////////////////////

std::vector<his_gen::Event_type> dd::Get_event_types()
{
  return s_event_types;
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Data_definitions& /*data_definitions*/)
{
  json = nlohmann::json
      {
          {"entity_type_relationship_types", dd::s_entity_type_relationship_types},
          {"entity_type_event_types", dd::s_entity_type_event_types},
          {"entity_types", dd::s_entity_types},
          {"relationship_type", dd::s_relationship_types},
          {"event_types", dd::s_event_types}
      };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Data_definitions& /*data_definitions*/)
{
  json.at("entity_type_relationship_types").get_to(dd::s_entity_type_relationship_types);
  json.at("entity_type_event_types").get_to(dd::s_entity_type_event_types);

  dd::Initialize_composite_data();
}

///////////////////////////////////////////////////////////////////////
