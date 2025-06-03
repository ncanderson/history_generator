/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <generators/narrators/end_times_era_narrator.h>

using et_nar = his_gen::End_times_era_narrator;

///////////////////////////////////////////////////////////////////////

et_nar::End_times_era_narrator(const his_gen::Data_access_manager& data_access_manager)
  :
  Narrator_base()
{
}

///////////////////////////////////////////////////////////////////////

void et_nar::Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                             int64_t entities_per_tick)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////

// TODO: expand to include entity type via switch case
std::shared_ptr<his_gen::Entity_base> et_nar::create_entity()
{
  // NOOP
  return nullptr;
}

///////////////////////////////////////////////////////////////////////

