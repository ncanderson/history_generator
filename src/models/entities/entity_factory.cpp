/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Application files
#include <models/entities/entity_factory.h>
#include <models/entities/entity_base.h>
#include <models/entities/entity_sentient.h>
#include <models/entities/entity_deity.h>

///////////////////////////////////////////////////////////////////////

std::shared_ptr<his_gen::Entity_base> his_gen::Entity_factory::Create_entity(const his_gen::EEntity_type entity_type,
                                                                             const uint64_t current_tick)
{
  std::shared_ptr<his_gen::Entity_base> new_entity;

  switch(entity_type)
  {
    case his_gen::EEntity_type::EENTITY_TYPE_Deity:
    {
      new_entity = std::make_shared<his_gen::Entity_deity>(current_tick);
    }
    break;

    case his_gen::EEntity_type::EENTITY_TYPE_Sentient:
    {
      new_entity = std::make_shared<his_gen::Entity_sentient>(entity_type,
                                                              current_tick);
    }
    break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Artifact:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Beast:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Clan_tribe:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Culture:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Ethnicity:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Event:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Faction:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_House:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Idea:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Institution:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Language:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Legend:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Monster:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Nation:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Order:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Pantheon:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Phenomenon:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Region:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Religion:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Ruin:
    //break;
    //case his_gen::EEntity_type::EENTITY_TYPE_Settlement:
    //break;
    default:
      // Unrecognized value
      his_gen::Print_to_cout("Entity type not implemented yet");
      throw std::invalid_argument("Entity type enumeration not found " +
                                  std::string(his_gen::Enum_to_string(entity_type,
                                                                      entity_type_lookup)));
  }

  new_entity->Initialize();
  return new_entity;
}

///////////////////////////////////////////////////////////////////////
