/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <utils/mythological_era_config.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::Mythological_era_config::Mythological_era_config()
{

}

///////////////////////////////////////////////////////////////////////

his_gen::Mythological_era_config::Mythological_era_config(json from_json)
  :
  Myth_gen_ticks(from_json.at("myth_gen_ticks")),
  Max_entity_per_tick(from_json.at("max_entity_per_tick")),
  Full_random_reproduction(from_json.at("full_random_reproduction")),
  Max_event_per_tick(from_json.at("max_event_per_tick")),
  Max_event_per_entity_per_tick(from_json.at("max_event_per_entity"))
{
  his_gen::Print_to_cout("Myth gen config");
  his_gen::Print_key_value("Myth_gen_ticks", Myth_gen_ticks);
  his_gen::Print_key_value("Max_entity_per_tick", Max_entity_per_tick);
  his_gen::Print_key_value("Full_random_reproduction", Full_random_reproduction);
  his_gen::Print_key_value("Max_event_per_entity_per_tick", Max_event_per_entity_per_tick);
  his_gen::Print_key_value("Max_event_per_tick", Max_event_per_tick);
  his_gen::Print_to_cout("===============");
}

///////////////////////////////////////////////////////////////////////
