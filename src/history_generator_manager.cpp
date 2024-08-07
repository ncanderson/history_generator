#include <history_generator_manager.h>
#include <utils/history_manager_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_manager::History_generator_manager(his_gen::History_generator_config &his_gen_config)
  :
    m_his_gen_config(his_gen_config),
    m_current_era(his_gen::Era::ERA_Unknown),
    m_myth_gen(std::make_shared<his_gen::Mythology_generator>()),
    m_hist_gen(std::make_shared<his_gen::History_generator>()),
    m_end_times_gen(std::make_shared<his_gen::End_times_generator>()),
    m_num_iterations(0)
{

}

///////////////////////////////////////////////////////////////////////

his_gen::Era his_gen::History_generator_manager::Run()
{
  switch(m_current_era)
  {
    case his_gen::Era::ERA_Unknown:
      his_gen::Print_to_cout("Initialize generation");
      m_current_era = his_gen::Era::ERA_Mythology;
      break;

    case his_gen::Era::ERA_Mythology:
      his_gen::Print_to_cout("Begin Mythology Generation");

      // Run through one generation iteration
      m_myth_gen->Run();

      if(m_myth_gen->Get_generation_complete())
      {
        m_current_era = his_gen::Era::ERA_History;
      }
      break;

    case his_gen::Era::ERA_History:
      his_gen::Print_to_cout("Begin History Generation");

      // Run through one generation iteration
      m_hist_gen->Run();

      if(m_hist_gen->Get_generation_complete())
      {
        m_current_era = his_gen::Era::ERA_End_times;
      }
      break;

    case his_gen::Era::ERA_End_times:
      his_gen::Print_to_cout("Begin End Times Generation");

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
