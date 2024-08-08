#include <generators/mythological_era_generator.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::Mythological_era_generator::Mythological_era_generator()
    :
    his_gen::Generator_base(false, his_gen::Stage::STAGE_Init)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Mythological_era_generator::Run()
{
  switch(m_current_stage)
  {
    case STAGE_Init:
      his_gen::Print_to_cout("Begin stage init");
      // Yes, do this
      // load some definitions about the generation from external config
      // Establish end state for the Age of Mythology
      // Generate the progenitor deity
      // Establish means by which this deity will reproduce

      // Maybe do this
      // figure out what the divine language looks like?

      m_current_stage = STAGE_Run;
      break;

    case STAGE_Run:
      his_gen::Print_to_cout("Begin stage run");

      // Generate
      // Every runtick:
      // - Generate entities

      m_current_stage = STAGE_Terminate;
      break;

    case STAGE_Terminate:
      his_gen::Print_to_cout("Begin stage terminate");

      // Define the sentients that will be created for later phases
      // establish how gods remove themselves from the world

      // TODO make this conditional?
      Set_generation_complete(true);

      break;
    default:
      his_gen::Print_to_cout("Default");
  }
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
