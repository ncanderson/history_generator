#include <history_generator_manager.h>
#include <utils/history_manager_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_manager::History_generator_manager()
  :
  m_current_era(his_gen::Era::ERA_Unknown)
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
      his_gen::Print_to_cout("Init");
      m_current_era = his_gen::Era::ERA_Mythology;
      break;

    case his_gen::Era::ERA_Mythology:
      his_gen::Print_to_cout("in Myth");

      if(myth_gen_complete)
      {
        m_current_era = his_gen::Era::ERA_History;
      }
      break;

    case his_gen::Era::ERA_History:
      his_gen::Print_to_cout("in History");

      if(history_gen_complete)
      {
        m_current_era = his_gen::Era::ERA_End_times;
      }
      break;

    case his_gen::Era::ERA_End_times:
      his_gen::Print_to_cout("in End times");

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
