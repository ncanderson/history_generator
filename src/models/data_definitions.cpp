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
std::vector<his_gen::Entity_type> dd::s_entity_types;
std::vector<his_gen::Relationship_type> dd::s_relationship_types;
std::vector<his_gen::Event_type> dd::s_event_types;

std::map<his_gen::EEntity_type, std::vector<his_gen::EEvent_type>> dd::s_entity_events;
std::map<his_gen::EEntity_type, std::vector<his_gen::ERelationship_type>> dd::s_entity_relationships;

///////////////////////////////////////////////////////////////////////

void dd::Initialize()
{
  initialize_members_from_enums();
  build_entity_relationships(s_entity_type_relationship_types);
  build_entity_events(s_entity_type_event_types);
}

///////////////////////////////////////////////////////////////////////

his_gen::EEntity_type dd::Get_rand_entity_type()
{
  return his_gen::dice::Get_random_element(s_entity_types).Get_entity_type();
}

///////////////////////////////////////////////////////////////////////

his_gen::EEvent_type dd::Get_rand_entity_event(const his_gen::EEntity_type& entity)
{
  return his_gen::dice::Get_random_element(s_entity_events[entity]);
}

///////////////////////////////////////////////////////////////////////

his_gen::ERelationship_type dd::Get_rand_entity_relationship(const his_gen::EEntity_type& entity)
{
  return his_gen::dice::Get_random_element(s_entity_relationships[entity]);
}

///////////////////////////////////////////////////////////////////////

void dd::build_entity_events(const Entity_type_event_types& ent_event)
{
  for (auto& it : ent_event)
  {
    s_entity_events[it.Get_entity_type()].push_back(it.Get_event_type());
  }
}

///////////////////////////////////////////////////////////////////////

void dd::build_entity_relationships(const Entity_type_relationship_types& ent_rel)
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
    // This will skip the creation of an Entity_type object for the 'Count' member,
    // which is just used as a helper in the templated lookup schema
    if (e == his_gen::EENTITY_TYPE_Count)
    {
      continue;
    }
    Entity_type ent_type = Entity_type(e);
    s_entity_types.push_back(ent_type);
  }

  // Populate Relationship_types from all enum values
  s_relationship_types.clear();
  for (auto r : magic_enum::enum_values<his_gen::ERelationship_type>())
  {
    // This will skip the creation of a Relationship_type object for the 'Count' member,
    // which is just used as a helper in the templated lookup schema
    if (r == his_gen::ERELATIONSHIP_TYPE_Count)
    {
      continue;
    }
    Relationship_type rel_type = Relationship_type(r);
    s_relationship_types.push_back(rel_type);
  }

  // Populate Event_types from all enum values
  s_event_types.clear();
  for (auto ev : magic_enum::enum_values<his_gen::EEvent_type>())
  {
    // This will skip the creation of an Event_type object for the 'Count' member,
    // which is just used as a helper in the templated lookup schema
    if (ev == his_gen::EEVENT_TYPE_Count)
    {
      continue;
    }
    Event_type evt_type = Event_type(ev);
    s_event_types.push_back(evt_type);
  }
}

///////////////////////////////////////////////////////////////////////
