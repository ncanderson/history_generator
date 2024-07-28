#include <history_generator_manager.h>

///////////////////////////////////////////////////////////////////////

his_gen::History_generator_manager::History_generator_manager()
  :
  m_current_era(his_gen::Era::ERA_Mythology)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::History_generator_manager::Run()
{
  switch(m_current_era)
  {
    case his_gen::Era::ERA_Mythology:
      m_current_era = his_gen::Era::ERA_History;
      break;

    case his_gen::Era::ERA_History:
      m_current_era = his_gen::Era::ERA_Terminate;
      break;

    case his_gen::Era::ERA_Terminate:

      break;
  }
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
