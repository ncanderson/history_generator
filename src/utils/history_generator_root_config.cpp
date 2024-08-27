/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <utils/history_generator_root_config.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_root_config::History_generator_root_config()
{

}

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_root_config::History_generator_root_config(json from_json)
  :
    Data_access_type(from_json.at("data_access_type")),
    m_myth_era_config(from_json.at("myth_gen_config")),
    m_hist_era_config(from_json.at("hist_gen_config")),
    m_end_times_era_config(from_json.at("end_times_gen_config"))
{
  his_gen::Print_to_cout("Global generator config");
  his_gen::Print_key_value("data_access_type", Data_access_type);
  his_gen::Print_to_cout("===============");
}

///////////////////////////////////////////////////////////////////////
