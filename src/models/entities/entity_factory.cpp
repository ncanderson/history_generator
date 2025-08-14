/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Application files
#include <models/entities/entity_factory.h>
#include <models/entities/entity_base.h>
#include <models/entities/entity_sentient.h>

///////////////////////////////////////////////////////////////////////

std::shared_ptr<his_gen::Entity_base> his_gen::Entity_factory::Create_entity(const his_gen::EEntity_type entity_type,
                                                                             const uint64_t current_tick)
{
  switch(entity_type)
  {
    case his_gen::EEntity_type::EENTITY_TYPE_Deity:
    {
      return std::make_shared<his_gen::Entity_sentient>(entity_type,
                                                        current_tick);
    }
    break;

    default:
      // Unrecognized value
      throw std::invalid_argument("Event type enumeration not found");
  }

}

///////////////////////////////////////////////////////////////////////
