/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <generators/mythological_era_generator.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::Mythological_era_generator::Mythological_era_generator(his_gen::History_generator_root_config &his_gen_config,
                                                                models::Generated_history &generated_history)
    :
    his_gen::Generator_base(false, his_gen::Stage::STAGE_Init, his_gen_config),
    m_generated_history(generated_history)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Mythological_era_generator::Run()
{
  his_gen::Print_to_cout("Current Stage: " +
                         his_gen::Get_current_stage(m_current_stage));

  switch(m_current_stage)
  {
    case STAGE_Init:
    {
      // Yes, do this
      // load some definitions about the generation from external config
      // Establish end state for the Age of Mythology
      // Generate the progenitor deity
      // Establish means by which this deity will reproduce

      // Maybe do this
      // figure out what the divine language looks like?

      // Create a new ultimate parent entity
      models::Entity new_entity = create_entity();

      m_current_stage = STAGE_Run;
    }
      break;

    case STAGE_Run:
    {
      // Generate
      // Every runtick:
      // - Generate entities

      m_current_stage = STAGE_Terminate;
    }
      break;

    case STAGE_Terminate:
    {
      // Define the sentients that will be created for later phases
      // establish how gods remove themselves from the world

      // TODO make this conditional?
      Set_generation_complete(true);
    }
      break;

    default:
    {
      his_gen::Print_to_cout("Default");
    }
  }
}

///////////////////////////////////////////////////////////////////////

models::Entity his_gen::Mythological_era_generator::create_entity()
{
  models::Entity new_entity = models::Entity("TEST name myth");
  m_generated_history.Entities.push_back(new_entity);
  return new_entity;
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
