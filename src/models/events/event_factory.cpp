/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Application files
#include <models/events/event_factory.h>
#include <models/events/seek_partner_event.h>

///////////////////////////////////////////////////////////////////////

std::shared_ptr<his_gen::Event_base> his_gen::Event_factory::Create_event(his_gen::EEvent_type event_type)
{
  std::shared_ptr<his_gen::Event_base> event_return;

  switch(event_type)
  {
    case his_gen::EEvent_type::EEVENT_TYPE_Seek_partner:
    {
      event_return = std::make_shared<his_gen::Seek_partner_event>();
    }
    break;
  }

  return event_return;
}

///////////////////////////////////////////////////////////////////////
