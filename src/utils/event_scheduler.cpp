/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <utils/event_scheduler.h>

///////////////////////////////////////////////////////////////////////

using sched = his_gen::Event_scheduler;

///////////////////////////////////////////////////////////////////////

sched::Event_scheduler()
  :
  m_scheduled_events()
{ }

//////////////////////////////////////////////////////////////////////

void sched::Schedule_event(std::shared_ptr<Event_base> event_to_schedule)
{
  m_scheduled_events.push(event_to_schedule);
}

///////////////////////////////////////////////////////////////////////

void sched::Schedule_distant_event(std::shared_ptr<Event_base> event_to_schedule,
                                   uint32_t tick_to_run)
{
  // NOOP
  // Something here but I'm not sure how to implement this yet
}

///////////////////////////////////////////////////////////////////////

std::shared_ptr<his_gen::Event_base> sched::Get_next_event()
{
  std::shared_ptr<his_gen::Event_base> event = m_scheduled_events.front();
  m_scheduled_events.pop();
  return event;
}

///////////////////////////////////////////////////////////////////////

bool sched::More_events_to_run()
{
  return !m_scheduled_events.empty();
}

///////////////////////////////////////////////////////////////////////

void sched::Merge_scheduled_events(Event_scheduler scheduler_to_merge)
{
  Scheduled_events events = scheduler_to_merge.Get_all_scheduled_events();
  while(scheduler_to_merge.More_events_to_run())
  {
    Schedule_event(scheduler_to_merge.Get_next_event());
  }
}

///////////////////////////////////////////////////////////////////////
