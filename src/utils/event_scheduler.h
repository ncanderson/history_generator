/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef EVENT_SCHEDULER_H
#define EVENT_SCHEDULER_H

// Standard libs
#include <map>
#include <deque>
#include <memory>
#include <boost/uuid/uuid.hpp>

// JSON

// Application file
#include <defs/history_generator_defs.h>
#include <models/entities/entity_base.h>

namespace his_gen
{
/**
 * @brief Forward declaration of Event_base
 */
class Event_base;

/**
 * @brief Thin wrapper around Event_base to facilitate event scheduling
 * in the future.
 * @details This class uses private data members, but declares Event_scheduler
 * as a friend, allowing access from that class.
 */
class Scheduled_event
{
public:

  friend class Event_scheduler;

private:
  /**
   * @brief The entity that will trigger this event
   */
  std::shared_ptr<his_gen::Entity_base>& m_triggering_entity;

  /**
   * @brief The type of event that will be scheduled to run
   */
  const his_gen::EEvent_type m_scheduled_event_type;

  /**
   * @brief Private constructor
   * @param triggering_entity The entity that will trigger this event
   * @param scheduled_event_type The type of event to be scheduled
   */
  Scheduled_event(std::shared_ptr<his_gen::Entity_base>& triggering_entity,
                  const his_gen::EEvent_type scheduled_event_type)
    :
      m_triggering_entity(triggering_entity),
      m_scheduled_event_type(scheduled_event_type)
  { }

}; // class Scheduled_event

/**
 * @brief Wrapper class to faciliate the scheduling of future events
 * @details This class will manage a map, used to schedule events for
 * future generation ticks.
 */
class Event_scheduler
{
public:

  /**
   * @brief Constructor
   */
  Event_scheduler();

  /**
   * @brief Destructor
   */
  ~Event_scheduler() = default;

  /**
   * Usings
   */
  using Events_queue = std::deque<Scheduled_event>;
  using Scheduled_events = std::map<uint32_t, Events_queue, std::less<uint32_t>>;

  /**
   * @brief Schedule an event to run
   * @param triggering_entity The entity that will trigger this event
   * @param event_type_to_schedule The event type to schedule
   * @param tick_to_run The tick to run the event in
   */
  void Schedule_event(std::shared_ptr<his_gen::Entity_base>& triggering_entity,
                      const his_gen::EEvent_type event_type_to_schedule,
                      const uint32_t tick_to_run);

  /**
   * @brief Return the next event, and remove it from the schedule
   * @param current_tick The tick to get an event from
   * @return A pointer to the next event
   */
  std::shared_ptr<Event_base> Prepare_next_event(const uint32_t current_tick);

  /**
   * @brief More_events_to_run
   * @param tick_to_check The tick to check for events on
   * @return True if there are more events to run, otherwise false.
   */
  bool More_events_to_run(const uint32_t tick_to_check) const;

  /**
   * @brief Merge all scheduled events from another instance of this class
   * into this one.
   * @details This function will not dispose of the argued `scheduler_to_merge`,
   * but expects callers to manage its lifetime and scope. It will, however,
   * pop all events off of that queue. If a caller wants to copy events,
   * and retain the scheduled events on both objects, use `Cop_scheduled_events`
   * instead.
   * @param scheduler_to_merge The other scheduler instance to merge.
   */
  void Merge_scheduled_events(Event_scheduler& scheduler_to_merge);

  /**
   * @brief Copy all scheduled events from another instance of this class
   * into this one, retaining the events on both objects.
   * @details The copy performed is not a two-way copy, but only copies
   * the events from the argued instance onto the calling instance.
   * This function will not dispose of the argued `scheduler_to_merge`,
   * but expects callers to manage its lifetime and scope.
   * @param scheduler_to_copy The other scheduler instance to copy.
   */
  void Copy_scheduled_events(const Event_scheduler& scheduler_to_copy);

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Queue of events that have been scheduled for the next generation tick
   */
  Scheduled_events m_scheduled_events;

  // Implementation
  /**
   * @brief Schedule an event to run
   * @details Private function, allowing easier scheduling within this class.
   * External classes won't have access to the Scheduled_event class, so should
   * use objects available to them when scheduling.
   * @param scheduled_event The event to schedule
   * @param tick_to_run The tick to run the event in
   */
  void schedule_event(const Scheduled_event& scheduled_event,
                      const uint32_t tick_to_run);

  /**
   * @brief Pop the next event, removing it from the queue
   * @param tick_to_pop The tick to pop the event from
   * @return A Scheduled_event instance containing meta-data for the schedule
   * event to be run
   */
  Scheduled_event pop_next_event(const uint32_t tick_to_pop);

  /**
   * @brief Get all scheduled events
   * @return The full list of scheduled events
   */
  const Scheduled_events& get_all_scheduled_events() const;

  /**
   * @brief Get all scheduled events at the argued tick
   * @param tick_to_get Tick to get events for
   * @return All scheduled events at `tick_to_get`
   */
  const Events_queue& get_all_scheduled_events(const uint32_t tick_to_get) const;

}; // class Event_scheduler
}  // namespace his_gen

#endif // EVENT_SCHEDULER_H
