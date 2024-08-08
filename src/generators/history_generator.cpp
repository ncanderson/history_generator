#include <generators/history_generator.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::History_generator::History_generator()
    :
    his_gen::Generator_base(false, his_gen::Stage::STAGE_Init)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::History_generator::Run()
{
  switch(m_current_stage)
  {
    case STAGE_Init:
      his_gen::Print_to_cout("Begin stage init");

      m_current_stage = STAGE_Run;
      break;

    case STAGE_Run:
      his_gen::Print_to_cout("Begin stage run");

      m_current_stage = STAGE_Terminate;
      break;

    case STAGE_Terminate:
      his_gen::Print_to_cout("Begin stage terminate");

      // TODO make this conditional?
      Set_generation_complete(true);

      break;
    default:
      his_gen::Print_to_cout("Default");
  }
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
