/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Application files
#include <models/events/event_factory.h>
#include <models/events/seek_partner_event.h>

///////////////////////////////////////////////////////////////////////

std::shared_ptr<his_gen::Event_base> his_gen::Event_factory::Create_event(his_gen::EEvent_type event_type,
                                                                          std::shared_ptr<Entity_base>& triggering_entity)
{
  switch(event_type)
  {
    case his_gen::EEvent_type::EEVENT_TYPE_Seek_partner:
    {
      return std::make_shared<his_gen::Seek_partner_event>(triggering_entity);
    }
    break;

    default:
      // Unrecognized value
      throw std::invalid_argument("Event type enumeration not found");
  }


}

///////////////////////////////////////////////////////////////////////
