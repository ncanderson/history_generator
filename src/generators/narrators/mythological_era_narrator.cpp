/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard libs

// Application files
#include <generators/narrators/mythological_era_narrator.h>
#include <models/entities/entity_deity.h>
#include <models/entities/entity_sentient.h>
#include <models/entities/entity_factory.h>
#include <models/events/event_factory.h>
#include <models/events/seek_partner_event.h>
#include <utils/dice_rolls.h>

using myth_nar = his_gen::Mythological_era_narrator;

///////////////////////////////////////////////////////////////////////

myth_nar::Mythological_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                                    const his_gen::History_generator_root_config& his_gen_config,
                                    const std::shared_ptr<his_gen::Data_definitions> data_definitions)
  :
  Narrator_base(data_definitions),
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

void myth_nar::Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                               const uint64_t current_tick)
{
  for(int64_t tick_count = 0; tick_count < m_config.Get_myth_config().Max_entity_per_tick; tick_count++)
  {
    // A random entity type
    EEntity_type entity_type = m_data_definitions->Get_rand_entity_type();

    std::shared_ptr<his_gen::Entity_base> new_entity = his_gen::Entity_factory::Create_entity(entity_type,
                                                                                              current_tick);

    // Create the entity
    entities.push_back(new_entity);
  }
}

///////////////////////////////////////////////////////////////////////

void myth_nar::Manage_events(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                             std::vector<std::shared_ptr<his_gen::Event_base>>& events,
                             const uint64_t current_tick)
{
  // Run events that were scheduled previously
  run_scheduled_events(entities);

  // TODO Put this into another helper function or something?
  // Create new events and run them
  for(int64_t tick_count = 0; tick_count < m_config.Get_myth_config().Max_event_per_tick;tick_count++)
  {
    // A random entity
    std::shared_ptr<his_gen::Entity_base> triggering_entity = his_gen::dice::Get_random_element(entities);

    // Make sure we don't create more than one event per entity per loop, but still allow events
    // to fire on tick 0
    if(triggering_entity->Get_last_event_triggered() >= current_tick && current_tick > 0)
    {
      // Continuing here will still increment the event counter, so the final 'events per tick' will
      // less than the max, but this will avoid infinite loops
      continue;
    }

    // A random event
    EEvent_type event_type = m_data_definitions->Get_rand_entity_event(triggering_entity->Get_entity_type());
    // Create the event
    std::shared_ptr<his_gen::Event_base> new_event = his_gen::Event_factory::Create_event(event_type,
                                                                                          triggering_entity,
                                                                                          current_tick);
    // Run the event
    new_event->Run(entities, m_event_scheduler);

    // Add the event to the list if something changed
    if(new_event->Created_meaningful_change())
    {
      // Set the tick on the entity, so it won't be selected again this loop
      triggering_entity->Set_last_event_triggered(current_tick);
      events.push_back(new_event);
    }
    else
    {
      his_gen::Print_to_cout(new_event->Get_name() + " " +
                             "event run; no meaningful change occured");
    }
  }
}

///////////////////////////////////////////////////////////////////////
