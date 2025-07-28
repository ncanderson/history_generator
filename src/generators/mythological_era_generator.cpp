/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <generators/mythological_era_generator.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::Mythological_era_generator::Mythological_era_generator(const his_gen::History_generator_root_config& his_gen_config,
                                                                his_gen::Generated_history& generated_history,
                                                                const his_gen::Data_access_manager& data_access_manager,
                                                                const std::shared_ptr<his_gen::Data_definitions> data_definitions)
  :
  his_gen::Generator_base(his_gen_config,
                          generated_history,
                          data_access_manager,
                          data_definitions),
  m_myth_narrator(data_access_manager, his_gen_config, data_definitions)
{
  m_generator_ticks = his_gen_config.Get_myth_config().Myth_gen_ticks;
  m_entities_per_tick = his_gen_config.Get_myth_config().Max_entity_per_tick;
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
      // Create a new ultimate parent entity
      m_myth_narrator.Create_progenitor_deity(m_generated_history.Entities);

      m_current_stage = STAGE_Run;
    }
      break;

    case STAGE_Run:
    {
      // Generate the desired number of entities for this tick
      m_myth_narrator.Create_entities(m_generated_history.Entities,
                                      m_entities_per_tick);

      m_myth_narrator.Handle_events(m_generated_history.Entities);




      //// Do they like each other?
      //m_myth_narrator.Run_entity_attraction(m_generated_history.Entities,
      //                                      m_generated_history.Entity_relationships);

      // Increment run-time ticks
      m_ticks_completed++;

      // Check exit state, move to terminate if we've completed enough ticks
      if(m_ticks_completed >= m_generator_ticks)
      {
        m_current_stage = STAGE_Terminate;
      }
    }
      break;

    case STAGE_Terminate:
    {
      // Define the sentients that will be created for later phases
      // establish how gods remove themselves from the world

      // Write the generated history out
      m_data_access_manager.Write_history(m_generated_history);

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
