/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <utils/historical_era_config.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::Historical_era_config::Historical_era_config()
{

}

///////////////////////////////////////////////////////////////////////

his_gen::Historical_era_config::Historical_era_config(json from_json)
    :
    Hist_gen_ticks(from_json.at("hist_gen_ticks")),
    Max_entity_per_tick(from_json.at("max_entity_per_tick"))
{
  his_gen::Print_to_cout("Historical gen config");
  his_gen::Print_key_value("Hist_gen_ticks", Hist_gen_ticks);
  his_gen::Print_key_value("Max_entity_per_tick", Max_entity_per_tick);
  his_gen::Print_to_cout("===============");
}

///////////////////////////////////////////////////////////////////////
