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
  switch(m_current_era)
  {
    case his_gen::Era::ERA_Unknown:
      his_gen::Print_to_cout("Init");
      m_current_era = his_gen::Era::ERA_Mythology;
      break;

    case his_gen::Era::ERA_Mythology:
      his_gen::Print_to_cout("in Myth");
      m_current_era = his_gen::Era::ERA_History;
      break;

    case his_gen::Era::ERA_History:
      his_gen::Print_to_cout("in History");
      m_current_era = his_gen::Era::ERA_Terminate;
      break;

    case his_gen::Era::ERA_Terminate:
      his_gen::Print_to_cout("in Term");
      break;

    default:
      m_current_era = his_gen::Era::ERA_Unknown;
  }

  return m_current_era;
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
