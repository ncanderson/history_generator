/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <generators/narrators/historical_era_narrator.h>

using hist_nar = his_gen::Historical_era_narrator;

///////////////////////////////////////////////////////////////////////

hist_nar::Historical_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                                  const his_gen::History_generator_root_config& his_gen_config)
  :
  Narrator_base()
{
}

///////////////////////////////////////////////////////////////////////

void hist_nar::Create_entities(his_gen::Entities& entities,
                               const uint64_t current_tick)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////

void hist_nar::Manage_events(his_gen::Generated_history& history_of_the_world,
                             const uint64_t current_tick)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
