#include <utils/history_generator_root_config.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_root_config::History_generator_root_config()
  :
    Global_config_placeholder(false)
{

}

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_root_config::History_generator_root_config(json from_json)
  :
    Global_config_placeholder(from_json.at("global_config_placeholder")),
    m_myth_era_config(from_json.at("myth_gen_config")),
    m_hist_era_config(from_json.at("hist_gen_config")),
    m_end_times_era_config(from_json.at("end_times_gen_config"))
{
  his_gen::Print_to_cout("Global generator config");
  his_gen::Print_key_value("Global_config_placeholder", Global_config_placeholder);
  his_gen::Print_to_cout("===============");
}

///////////////////////////////////////////////////////////////////////
