/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <history_generator_manager.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_manager::History_generator_manager(his_gen::History_generator_root_config &his_gen_config,
                                                              models::Generated_history &generated_history,
                                                              his_gen::Data_access_manager &data_access_manager)
  :
    m_his_gen_config(his_gen_config),
    m_generated_history(generated_history),
    m_current_era(his_gen::Era::ERA_Unknown),
    m_myth_gen(std::make_shared<his_gen::Mythological_era_generator>(his_gen_config,
                                                                     generated_history,
                                                                     data_access_manager)),
    m_hist_gen(std::make_shared<his_gen::Historical_era_generator>(his_gen_config,
                                                                   generated_history,
                                                                   data_access_manager)),
    m_end_times_gen(std::make_shared<his_gen::End_times_era_generator>(his_gen_config,
                                                                       generated_history,
                                                                       data_access_manager)),
    m_num_iterations(0)
{

}

///////////////////////////////////////////////////////////////////////

his_gen::Era his_gen::History_generator_manager::Run()
{
  his_gen::Print_to_cout("Current Era: " +
                         his_gen::Get_current_era(m_current_era));

  switch(m_current_era)
  {
    case his_gen::Era::ERA_Unknown:
      m_current_era = his_gen::Era::ERA_Mythology;
      break;

    case his_gen::Era::ERA_Mythology:    
      // Run through one generation iteration
      m_myth_gen->Run();

      if(m_myth_gen->Get_generation_complete())
      {
        m_current_era = his_gen::Era::ERA_History;
      }
      break;

    case his_gen::Era::ERA_History:
      // Run through one generation iteration
      m_hist_gen->Run();

      if(m_hist_gen->Get_generation_complete())
      {
        m_current_era = his_gen::Era::ERA_End_times;
      }
      break;

    case his_gen::Era::ERA_End_times:
      // Run through one generation iteration
      m_end_times_gen->Run();

      if(m_end_times_gen->Get_generation_complete())
      {
        m_current_era = his_gen::Era::ERA_Terminate;
      }
      break;

    default:
      // Exit application if we don't know where we are
      m_current_era = his_gen::Era::ERA_Terminate;
  }

  // Iterate the counter
  // TODO: pass this to the child run functions?
  m_num_iterations++;

  return m_current_era;
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
