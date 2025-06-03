/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <generators/narrators/historical_era_narrator.h>

///////////////////////////////////////////////////////////////////////

his_gen::Historical_era_narrator::Historical_era_narrator(const his_gen::Data_access_manager& data_access_manager)
  :
  Narrator_base()
{
}

///////////////////////////////////////////////////////////////////////

void Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                     int64_t entities_per_tick)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
