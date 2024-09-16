/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <generators/mythological_era_generator.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::Mythological_era_generator::Mythological_era_generator(std::shared_ptr<his_gen::History_generator_root_config> his_gen_config,
                                                                std::shared_ptr<his_gen::Generated_history> generated_history,
                                                                std::unique_ptr<his_gen::Data_access_manager>& data_access_manager)
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
      his_gen::Entity entity1 = create_entity();
      his_gen::Entity entity2 = create_entity();

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

      // Write the generated history out
      m_data_access_manager->Write_history(m_generated_history);

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

his_gen::Entity his_gen::Mythological_era_generator::create_entity()
{
  his_gen::Entity new_entity = his_gen::Entity("did we do it chat?");
  m_generated_history->Entities.push_back(new_entity);
  return new_entity;
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
