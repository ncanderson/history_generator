/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#include <generators/mythological_era_generator.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

his_gen::Mythological_era_generator::Mythological_era_generator(const his_gen::History_generator_root_config& his_gen_config,
                                                                his_gen::Generated_history& generated_history,
                                                                const his_gen::Data_access_manager& data_access_manager,
                                                                const his_gen::Data_definitions& data_definitions)
    :
    his_gen::Generator_base(his_gen_config,
                            generated_history,
                            data_access_manager,
                            data_definitions),
    m_names(data_access_manager)
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
      create_progenitor_deity();

      m_current_stage = STAGE_Run;
    }
      break;

    case STAGE_Run:
    {
      // Generate the desired number of entities for this tick
      for(int64_t tick = 0; tick < m_entities_per_tick; tick++)
      {
        create_entity();
      }

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

void his_gen::Mythological_era_generator::create_progenitor_deity()
{
  //std::shared_ptr<his_gen::Entity_sentient> ptr = std::make_shared<his_gen::Entity_sentient>(his_gen::Entity_sentient("God", "the Allfather", false));
  //m_generated_history.Entities.emplace_back(std::make_shared<his_gen::Entity_sentient>(his_gen::Entity_sentient("God", "the Allfather", false)));

  std::shared_ptr<his_gen::Entity_sentient> ptr = std::make_shared<his_gen::Entity_sentient>("God", "the Allfather", false);
  m_generated_history.Entities.push_back(ptr);
}

///////////////////////////////////////////////////////////////////////

void his_gen::Mythological_era_generator::create_entity()
{
  m_generated_history.Entities.push_back(std::make_shared<his_gen::Entity_sentient>(m_names.Get_one_name(),
                                                                                    m_names.Get_one_title()));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
