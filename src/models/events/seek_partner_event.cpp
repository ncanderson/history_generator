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

void his_gen::Seek_partner_event::initialize_event()
{
  // TODO: implement initialize_event
}

///////////////////////////////////////////////////////////////////////

void his_gen::Seek_partner_event::run_event()
{
  // TODO: implement run_event
}

///////////////////////////////////////////////////////////////////////

void his_gen::Seek_partner_event::conclude_event()
{
  // TODO: implement conclude_event
}

///////////////////////////////////////////////////////////////////////

std::vector<std::shared_ptr<his_gen::Event_base>> his_gen::Seek_partner_event::get_next_steps() const
{
  // TODO: implement get_next_steps
  return {};
}

///////////////////////////////////////////////////////////////////////
