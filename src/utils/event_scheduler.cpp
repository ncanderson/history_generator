/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <utils/event_scheduler.h>

///////////////////////////////////////////////////////////////////////

his_gen::Event_scheduler::Event_scheduler()
  :
  m_scheduled_events()
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Event_scheduler::Schedule_event(std::shared_ptr<Event_base> event_to_schedule)
{
  m_scheduled_events.push(event_to_schedule);
}

///////////////////////////////////////////////////////////////////////

void his_gen::Event_scheduler::Schedule_distant_event(std::shared_ptr<Event_base> event_to_schedule,
                                                      uint32_t tick_to_run)
{
  // NOOP
  // Something here but I'm not sure how to implement this yet
}

///////////////////////////////////////////////////////////////////////

std::shared_ptr<his_gen::Event_base> his_gen::Event_scheduler::Get_next_event()
{
  std::shared_ptr<his_gen::Event_base> event = m_scheduled_events.front();
  m_scheduled_events.pop();
  return event;
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Event_scheduler::More_events_to_run()
{
  return !m_scheduled_events.empty();
}

///////////////////////////////////////////////////////////////////////
