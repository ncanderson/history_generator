/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <generators/narrators/historical_era_narrator.h>

using hist_nar = his_gen::Historical_era_narrator;

///////////////////////////////////////////////////////////////////////

hist_nar::Historical_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                                  const his_gen::History_generator_root_config& his_gen_config,
                                  const std::shared_ptr<his_gen::Data_definitions> data_definitions)
  :
  Narrator_base(data_definitions)
{
}

///////////////////////////////////////////////////////////////////////

void hist_nar::Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                               int64_t entities_per_tick)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////

void hist_nar::Handle_events(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////

// TODO: expand to include entity type via switch case
std::shared_ptr<his_gen::Entity_base> hist_nar::create_entity()
{
  // NOOP
  return nullptr;
}

///////////////////////////////////////////////////////////////////////

