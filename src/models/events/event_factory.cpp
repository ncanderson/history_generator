/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Application files
#include <models/events/event_factory.h>
// Events
#include <models/events/event_base.h>
#include <models/events/seek_partner_event.h>
#include <models/events/courtship_event.h>
#include <models/events/reproduce_event.h>

///////////////////////////////////////////////////////////////////////

std::shared_ptr<his_gen::Event_base> his_gen::Event_factory::Create_event(const his_gen::EEvent_type event_type,
                                                                          std::shared_ptr<Entity_base>& triggering_entity,
                                                                          const uint64_t current_tick)
{
  std::shared_ptr<his_gen::Event_base> created_event;

  switch(event_type)
  {
    case his_gen::EEvent_type::EEVENT_TYPE_Seek_partner:
    {
      created_event = std::make_shared<his_gen::Seek_partner_event>(triggering_entity,
                                                                    current_tick);
      break;
    }
    case his_gen::EEvent_type::EEVENT_TYPE_Courtship:
    {
      created_event = std::make_shared<his_gen::Courtship_event>(triggering_entity,
                                                                 current_tick);
      break;
    }
    case his_gen::EEvent_type::EEVENT_TYPE_Reproduce:
    {
      created_event = std::make_shared<his_gen::Reproduce_event>(triggering_entity,
                                                                 current_tick);
      break;
    }

    default:
      // Unrecognized value
      throw std::invalid_argument("Event type enumeration not found");
  }
  triggering_entity->Accept_event(*created_event);
  return created_event;
}

///////////////////////////////////////////////////////////////////////
