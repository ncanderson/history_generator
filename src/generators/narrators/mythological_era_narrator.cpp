/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard libs

// Application files
#include <generators/narrators/mythological_era_narrator.h>
#include <models/entity_sentient.h>

using myth_nar = his_gen::Mythological_era_narrator;

///////////////////////////////////////////////////////////////////////

myth_nar::Mythological_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                            const his_gen::History_generator_root_config& his_gen_config)
  :
  Narrator_base(),
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
                                                 false);
  entities.push_back(ptr);
}

///////////////////////////////////////////////////////////////////////

void myth_nar::Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                               int64_t entities_per_tick)
{
  for(int64_t tick = 0; tick < entities_per_tick; tick++)
  {
    create_entity();
  }
}

///////////////////////////////////////////////////////////////////////

// TODO: expand to include entity type via switch case
std::shared_ptr<his_gen::Entity_base> myth_nar::create_entity()
{
  return std::make_shared<his_gen::Entity_sentient>(m_names.Get_one_name(),
                                                    m_names.Get_one_title(),
                                                    m_config.Get_myth_config().Full_random_reproduction);

}

///////////////////////////////////////////////////////////////////////
