/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <generators/end_times_era_generator.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::End_times_era_generator::End_times_era_generator(const his_gen::History_generator_root_config& his_gen_config,
                                                          his_gen::Generated_history& generated_history,
                                                          const his_gen::Data_access_manager& data_access_manager)
    :
    his_gen::Generator_base(his_gen_config,
                            generated_history,
                            data_access_manager)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::End_times_era_generator::Run()
{
  his_gen::Print_to_cout("Current Stage: " +
                         his_gen::Get_current_stage(m_current_stage));

  switch(m_current_stage)
  {
    case STAGE_Init:
      m_current_stage = STAGE_Run;
      break;

    case STAGE_Run:
      m_current_stage = STAGE_Terminate;
      break;

    case STAGE_Terminate:

      // TODO make this conditional?
      Set_generation_complete(true);

      break;
    default:
      his_gen::Print_to_cout("Default");
  }
}

///////////////////////////////////////////////////////////////////////

his_gen::Entity his_gen::End_times_era_generator::create_entity()
{
  his_gen::Entity new_entity = his_gen::Entity("TEST name end times");
  return new_entity;
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
