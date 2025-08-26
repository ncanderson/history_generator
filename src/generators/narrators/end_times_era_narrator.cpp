/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <generators/narrators/end_times_era_narrator.h>

using et_nar = his_gen::End_times_era_narrator;

///////////////////////////////////////////////////////////////////////

et_nar::End_times_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                               const his_gen::History_generator_root_config& his_gen_config)
  :
  Narrator_base()
{
}

///////////////////////////////////////////////////////////////////////

void et_nar::Create_entities(Entities& entities,
                             const uint64_t current_tick)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////

void et_nar::Manage_events(Entities& entities,
                           Events& events,
                           Entity_relationships& entity_relationships,
                           const uint64_t current_tick)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
