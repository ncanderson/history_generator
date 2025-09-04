/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/event_factory.h>
#include <utils/event_scheduler.h>

///////////////////////////////////////////////////////////////////////

using sched = his_gen::Event_scheduler;

///////////////////////////////////////////////////////////////////////

sched::Event_scheduler()
  :
  m_scheduled_events()
{ }

//////////////////////////////////////////////////////////////////////

void sched::Schedule_event(std::shared_ptr<his_gen::Entity_base>& triggering_entity,
                           const std::vector<boost::uuids::uuid>& target_ids,
                           const his_gen::EEvent_type event_type_to_schedule,
                           const uint32_t tick_to_run)
{
  m_scheduled_events[tick_to_run].emplace_back(Scheduled_event(triggering_entity,
                                                               target_ids,
                                                               event_type_to_schedule));
}

///////////////////////////////////////////////////////////////////////

std::shared_ptr<his_gen::Event_base> sched::Prepare_next_event(const uint32_t current_tick)
{
  Scheduled_event event_to_handle = pop_next_event(current_tick);

  // Construct and return the Event_base pointer
  return his_gen::Event_factory::Create_event(event_to_handle.m_scheduled_event_type,
                                              event_to_handle.m_triggering_entity,
                                              current_tick);
}

///////////////////////////////////////////////////////////////////////

bool sched::More_events_to_run(const uint32_t tick_to_check) const
{
  auto it = m_scheduled_events.find(tick_to_check);
  return it != m_scheduled_events.end() && !it->second.empty();
}

///////////////////////////////////////////////////////////////////////

void sched::Merge_scheduled_events(Event_scheduler& scheduler_to_merge)
{
  // Reference to incoming events for the Event_scheduler instance to merge
  // into this one.
  const Scheduled_events& events = scheduler_to_merge.get_all_scheduled_events();

  // Iterate through all keys in the scheduler_to_merge's map
  for (const auto& [tick, queue] : events)
  {
    // For this tick, process all events
    while(scheduler_to_merge.More_events_to_run(tick))
    {
      schedule_event(scheduler_to_merge.pop_next_event(tick), tick);
    }
  }
}

///////////////////////////////////////////////////////////////////////

void sched::Copy_scheduled_events(const Event_scheduler& scheduler_to_copy)
{
  const Scheduled_events& events = scheduler_to_copy.get_all_scheduled_events();

  for(const auto& [tick, deque] : events)
  {
    // Copy each Scheduled_event in the queue without modifying the source
    for (const auto& event : deque)
    {
      schedule_event(event, tick);
    }
  }
}

///////////////////////////////////////////////////////////////////////

void sched::schedule_event(const Scheduled_event& scheduled_event,
                           const uint32_t tick_to_run)
{
  m_scheduled_events[tick_to_run].emplace_back(scheduled_event);
}

///////////////////////////////////////////////////////////////////////

his_gen::Scheduled_event sched::pop_next_event(const uint32_t tick)
{
  auto it = m_scheduled_events.find(tick);
  if (it == m_scheduled_events.end() || it->second.empty())
  {
    throw std::runtime_error("No scheduled events for this tick");
  }

  Scheduled_event event_to_handle = it->second.front();
  it->second.pop_front();

  // Remove the key if the queue is now empty
  if (it->second.empty())
  {
    m_scheduled_events.erase(it);
  }

  return event_to_handle;
}

///////////////////////////////////////////////////////////////////////

const sched::Scheduled_events& sched::get_all_scheduled_events() const
{
  return m_scheduled_events;
}

///////////////////////////////////////////////////////////////////////

const sched::Events_queue& sched::get_all_scheduled_events(const uint32_t tick_to_get) const
{
  // Empty queue to return if there are no events
  static const Scheduled_events::mapped_type empty_queue{};

  auto it = m_scheduled_events.find(tick_to_get);
  if (it != m_scheduled_events.end())
  {
    // If found, return a reference to the queue in the map
    return it->second;
  }
  else
  {
    // Otherwise return the empty queue
    return empty_queue;
  }
}

///////////////////////////////////////////////////////////////////////
