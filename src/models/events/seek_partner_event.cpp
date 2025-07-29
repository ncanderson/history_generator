/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/seek_partner_event.h>

///////////////////////////////////////////////////////////////////////

his_gen::Seek_partner_event::Seek_partner_event(const std::string& name)
  :
  Event_base(name)
{ }

///////////////////////////////////////////////////////////////////////

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

std::vector<std::unique_ptr<his_gen::Event_base>> his_gen::Seek_partner_event::get_next_steps() const
{
  // TODO: implement get_next_steps
  return {};
}

///////////////////////////////////////////////////////////////////////
