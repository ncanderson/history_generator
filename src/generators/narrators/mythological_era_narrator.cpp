/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard libs

// Application files
#include <generators/narrators/mythological_era_narrator.h>
#include <models/entities/entity_sentient.h>
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

void myth_nar::Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities)
{
  for(int64_t tick_count = 0; tick_count < m_config.Get_myth_config().Max_entity_per_tick; tick_count++)
  {
    // A random entity type
    EEntity_type entity_type = m_data_definitions->Get_rand_entity_type();
    // TEMP
    // until we figure out how weight entities
    entity_type = EENTITY_TYPE_Deity;
    // TEMP
    // Create the entity
    entities.push_back(create_entity(entity_type));
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
    std::shared_ptr<his_gen::Event_base> new_event = his_gen::Event_factory::Create_event(event_type,
                                                                                          triggering_entity);
    // Run the event
    new_event->Run();
    // Add the event to the list
    events.push_back(new_event);
  }
}

///////////////////////////////////////////////////////////////////////

// TODO: figure out how to make this happen via factory maybe
//       add weights
std::shared_ptr<his_gen::Entity_base> myth_nar::create_entity(his_gen::EEntity_type entity_type)
{
  switch(entity_type)
  {
    case EENTITY_TYPE_Unknown:     break;
    case EENTITY_TYPE_Artifact:    break;
    case EENTITY_TYPE_Beast:       break;
    case EENTITY_TYPE_Clan_tribe:  break;
    case EENTITY_TYPE_Culture:     break;
    case EENTITY_TYPE_Deity:
    {
      return std::make_shared<his_gen::Entity_sentient>(m_names.Get_one_name(),
                                                        m_names.Get_one_title(),
                                                        EENTITY_TYPE_Deity,
                                                        m_config.Get_myth_config().Full_random_reproduction);
    }
    break;
    case EENTITY_TYPE_Ethnicity:   break;
    case EENTITY_TYPE_Event:       break;
    case EENTITY_TYPE_Faction:     break;
    case EENTITY_TYPE_House:       break;
    case EENTITY_TYPE_Idea:        break;
    case EENTITY_TYPE_Institution: break;
    case EENTITY_TYPE_Language:    break;
    case EENTITY_TYPE_Legend:      break;
    case EENTITY_TYPE_Monster:     break;
    case EENTITY_TYPE_Nation:      break;
    case EENTITY_TYPE_Order:       break;
    case EENTITY_TYPE_Pantheon:    break;
    case EENTITY_TYPE_Phenomenon:  break;
    case EENTITY_TYPE_Region:      break;
    case EENTITY_TYPE_Religion:    break;
    case EENTITY_TYPE_Ruin:        break;
    case EENTITY_TYPE_Sentient:    break;
    case EENTITY_TYPE_Settlement:  break;
    default:
      // Unrecognized value
      throw std::invalid_argument("Entity type enumeration not found");
  }
}

///////////////////////////////////////////////////////////////////////
