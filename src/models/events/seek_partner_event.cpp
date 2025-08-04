/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/seek_partner_event.h>

///////////////////////////////////////////////////////////////////////

his_gen::Seek_partner_event::Seek_partner_event(std::shared_ptr<Entity_base>& triggering_entity)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Seek_partner, triggering_entity)
{
  // Register the derived class with the JSON serializer
  Polymorphic_serializer<his_gen::Event_base>::register_types<his_gen::Event_base,
                                                              his_gen::Seek_partner_event>();
}

//////////////////////////////////////////////////////////////////////

void his_gen::Seek_partner_event::Run()
{
  his_gen::Print_to_cout("here we are in Run");
}

///////////////////////////////////////////////////////////////////////
