/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <generators/narrators/narrator_base.h>

using nar_base = his_gen::Narrator_base;

///////////////////////////////////////////////////////////////////////

nar_base::Narrator_base(const std::shared_ptr<his_gen::Data_definitions> data_definitions)
  :
  m_data_definitions(data_definitions)
{
}

///////////////////////////////////////////////////////////////////////

void nar_base::Run_entity_attraction(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                                     std::map<boost::uuids::uuid, std::shared_ptr<his_gen::Entity_relationship>>& enitity_relationships)
{
  // Check for entity attraction
  std::vector<std::pair<std::shared_ptr<his_gen::Entity_sentient>,
                        std::shared_ptr<his_gen::Entity_sentient>>> pairs;

  // Loop through all entities
  for(auto& it : entities)
  {
    // Vector to track attraction for this entity, so we can review mutual attraction
    std::vector<std::shared_ptr<his_gen::Entity_base>> i_love_these_people;

    // Compare to all other entities
    for(auto& inner : entities)
    {
      it->Is_attracted(inner, i_love_these_people);
    }

    // If this entity is attracted to any other entities, check for mutual attraction
    if(!i_love_these_people.empty())
    {
      for(auto& mutuals : i_love_these_people)
      {
        if(mutuals->Is_attracted(it))
        {
          std::pair<std::shared_ptr<his_gen::Entity_sentient>,
                    std::shared_ptr<his_gen::Entity_sentient>> attraction =
              std::make_pair(std::dynamic_pointer_cast<his_gen::Entity_sentient>(it),
                             std::dynamic_pointer_cast<his_gen::Entity_sentient>(mutuals));
          pairs.push_back(attraction);
        }
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////
