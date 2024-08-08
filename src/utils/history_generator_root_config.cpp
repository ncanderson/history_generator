#include <utils/history_generator_root_config.h>

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_root_config::History_generator_root_config()
  :
    Global_config_placeholder(false)
{

}

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_root_config::History_generator_root_config(json from_json)
  :
    Global_config_placeholder(from_json.at("global_config_placeholder"))
{

}

///////////////////////////////////////////////////////////////////////
