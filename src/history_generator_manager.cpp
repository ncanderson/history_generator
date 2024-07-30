#include <history_generator_manager.h>
#include <utils/history_manager_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_manager::History_generator_manager()
  :
    m_current_era(his_gen::Era::ERA_Unknown),
    m_myth_gen(std::make_shared<his_gen::Mythology_generator>()),
    m_hist_gen(std::make_shared<his_gen::History_generator>()),
    m_end_times_gen(std::make_shared<his_gen::End_times_generator>())
{

}

///////////////////////////////////////////////////////////////////////

his_gen::Era his_gen::History_generator_manager::Run()
{
  bool myth_gen_complete = false;
  bool history_gen_complete = false;
  bool end_times_gen_complete = false;

  switch(m_current_era)
  {
    case his_gen::Era::ERA_Unknown:
      his_gen::Print_to_cout("Initialize generation");
      m_current_era = his_gen::Era::ERA_Mythology;
      break;

    case his_gen::Era::ERA_Mythology:
      his_gen::Print_to_cout("Begin Mythology Generation");

      if(m_myth_gen->Get_generation_complete())
      {
        m_current_era = his_gen::Era::ERA_History;
      }
      break;

    case his_gen::Era::ERA_History:
      his_gen::Print_to_cout("Begin History Generation");

      if(history_gen_complete)
      {
        m_current_era = his_gen::Era::ERA_End_times;
      }
      break;

    case his_gen::Era::ERA_End_times:
      his_gen::Print_to_cout("Begin End Times Generation");

      if(end_times_gen_complete)
      {
        m_current_era = his_gen::Era::ERA_Terminate;
      }
      break;

    default:
      // Exit application if we don't know where we are
      m_current_era = his_gen::Era::ERA_Terminate;
  }

  return m_current_era;
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
