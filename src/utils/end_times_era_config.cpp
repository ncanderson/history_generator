#include <utils/end_times_era_config.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::End_times_era_config::End_times_era_config()
{

}

///////////////////////////////////////////////////////////////////////

his_gen::End_times_era_config::End_times_era_config(json from_json)
    :
    End_times_gen_ticks(from_json.at("end_times_gen_ticks")),
    Max_entity_per_tick(from_json.at("max_entity_per_tick")),
    Violent_end_times(from_json.at("violent_end_times"))
{
  his_gen::Print_to_cout("End times gen config");
  his_gen::Print_key_value("End_times_gen_ticks", End_times_gen_ticks);
  his_gen::Print_key_value("Max_entity_per_tick", Max_entity_per_tick);
  his_gen::Print_key_value("Violent_end_times", Violent_end_times);
  his_gen::Print_to_cout("===============");
}

///////////////////////////////////////////////////////////////////////
