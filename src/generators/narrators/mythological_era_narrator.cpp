/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard libs

// Application files
#include <generators/narrators/mythological_era_narrator.h>
#include <models/entities/entity_sentient.h>
#include <models/events/event_factory.h>
#include <utils/dice_rolls.h>

//test
#include <models/events/event_base.h>
#include <models/events/seek_partner_event.h>
//test

using myth_nar = his_gen::Mythological_era_narrator;

///////////////////////////////////////////////////////////////////////

myth_nar::Mythological_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                                    const his_gen::History_generator_root_config& his_gen_config,
                                    const std::shared_ptr<his_gen::Data_definitions> data_definitions)
  :
  Narrator_base(data_definitions),
  m_config(his_gen_config),
  m_names(data_access_manager)
{
}

///////////////////////////////////////////////////////////////////////

void myth_nar::Create_progenitor_deity(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities)
{
  std::shared_ptr<his_gen::Entity_sentient> ptr =
      std::make_shared<his_gen::Entity_sentient>("God",
                                                 "the Allfather",
                                                 EENTITY_TYPE_Deity,
                                                 false);
  entities.push_back(ptr);
}

///////////////////////////////////////////////////////////////////////

void myth_nar::Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                               int64_t entities_per_tick)
{
  for(int64_t tick_count = 0; tick_count < entities_per_tick; tick_count++)
  {
    entities.push_back(create_entity());
  }
}

///////////////////////////////////////////////////////////////////////

void myth_nar::Create_events(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                             std::vector<std::shared_ptr<his_gen::Event_base>>& events)
{
  for(int64_t tick_count = 0; tick_count < m_config.Get_myth_config().Max_event_per_tick; tick_count++)
  {
    // A random entity
    std::shared_ptr<his_gen::Entity_base> triggering_entity = his_gen::Get_random_element(entities);
    // A random event
    EEvent_type event_type = m_data_definitions->Get_rand_entity_event(triggering_entity->Get_entity_type());
    // Create the event
    //std::shared_ptr<his_gen::Event_base> new_event = his_gen::Event_factory::Create_event(event_type,
    //                                                                                      triggering_entity);

    std::shared_ptr<his_gen::Dummy_event> new_event = std::make_shared<his_gen::Dummy_event>(triggering_entity);

    // Add the event to the list
    events.push_back(new_event);
  }
}

///////////////////////////////////////////////////////////////////////

// TODO: expand to include entity type via switch case
std::shared_ptr<his_gen::Entity_base> myth_nar::create_entity()
{
  return std::make_shared<his_gen::Entity_sentient>(m_names.Get_one_name(),
                                                    m_names.Get_one_title(),
                                                    EENTITY_TYPE_Deity,
                                                    m_config.Get_myth_config().Full_random_reproduction);
}

///////////////////////////////////////////////////////////////////////
