/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <generators/historical_era_generator.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::Historical_era_generator::Historical_era_generator(his_gen::History_generator_root_config &his_gen_config,
                                                            models::Generated_history &generated_history,
                                                            his_gen::Data_access_manager &data_access_manager)
    :
    his_gen::Generator_base(false,
                            his_gen::Stage::STAGE_Init,
                            his_gen_config,
                            generated_history,
                            data_access_manager),
    m_generated_history(generated_history)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Historical_era_generator::Run()
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

models::Entity his_gen::Historical_era_generator::create_entity()
{
  models::Entity new_entity = models::Entity("TEST name history");
  return new_entity;
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
