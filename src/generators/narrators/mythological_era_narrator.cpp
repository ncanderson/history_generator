/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard libs

// Application files
#include <generators/narrators/mythological_era_narrator.h>
#include <models/data_definitions.h>
#include <models/entities/entity_deity.h>
#include <models/entities/entity_sentient.h>
#include <models/entities/entity_factory.h>
#include <models/events/event_factory.h>
#include <models/events/seek_partner_event.h>
#include <utils/dice_rolls.h>

using myth_nar = his_gen::Mythological_era_narrator;

///////////////////////////////////////////////////////////////////////

myth_nar::Mythological_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                                    const his_gen::History_generator_root_config& his_gen_config)
  :
  Narrator_base(),
  m_config(his_gen_config)
{
}

///////////////////////////////////////////////////////////////////////

void myth_nar::Create_progenitor_deity(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities)
{
  std::shared_ptr<his_gen::Entity_base> ptr = std::make_shared<his_gen::Entity_deity>("God",
                                                                                      "the Allfather",
                                                                                      0);
  entities.push_back(ptr);
}

///////////////////////////////////////////////////////////////////////

void myth_nar::Create_entities(Entities& entities,
                               const uint64_t current_tick)
{
  for(int64_t tick_count = 0; tick_count < m_config.Get_myth_config().Max_entity_per_tick; tick_count++)
  {
    // A random entity type
    EEntity_type entity_type = his_gen::Data_definitions::Get_rand_entity_type();

    std::shared_ptr<his_gen::Entity_base> new_entity = his_gen::Entity_factory::Create_entity(entity_type,
                                                                                              current_tick);

    // Create the entity
    entities.push_back(new_entity);
  }
}

///////////////////////////////////////////////////////////////////////

void myth_nar::Manage_events(Entities& entities,
                             Events& events,
                             Entity_relationships& entity_relationships,
                             const uint64_t current_tick)
{
  // Run events that were scheduled previously
  run_scheduled_events(entities, entity_relationships);

  // TODO Put this into another helper function or something?
  // Create new events and run them
  for(int64_t tick_count = 0; tick_count < m_config.Get_myth_config().Max_event_per_tick;tick_count++)
  {
    // A random entity
    std::shared_ptr<his_gen::Entity_base> triggering_entity = his_gen::dice::Get_random_element(entities);

    // A random event
    EEvent_type event_type = his_gen::Data_definitions::Get_rand_entity_event(triggering_entity->Get_entity_type());
    // Create the event
    std::shared_ptr<his_gen::Event_base> new_event = his_gen::Event_factory::Create_event(event_type,
                                                                                          triggering_entity,
                                                                                          current_tick);

    // Check the event for the entity
    if(triggering_entity->Event_is_valid(new_event->Get_event_type(), current_tick))
    {
      // Run the event
      new_event->Run(entities, entity_relationships, m_event_scheduler);
    }
    else
    {
      // Continuing here will still increment the event counter, so the final 'events per tick' will be
      // less than the max, but this will avoid infinite loops, or cases where there are few enough entities
      // that all of them trigger events this tick
      continue;
    }

    // Add the event to the list if something changed
    if(new_event->Created_meaningful_change())
    {
      events.push_back(new_event);
    }
  }
}

///////////////////////////////////////////////////////////////////////
