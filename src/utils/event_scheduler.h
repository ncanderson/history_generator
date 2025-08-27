/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef EVENT_SCHEDULER_H
#define EVENT_SCHEDULER_H

// Standard libs
#include <queue>
#include <memory>
#include <boost/uuid/uuid.hpp>

// JSON

// Application file

namespace his_gen
{
/**
 * @brief Forward declaration of Event_base
 */
class Event_base;

/**
 * @brief Thin wrapper around Event_base to facilitate event scheduling
 * in the future.
 */
struct Scheduled_event
{

  Scheduled_event

  /**
   * @brief The event to schedule
   */
  std::shared_ptr<his_gen::Event_base> m_scheduled_event;

  /**
   * @brief The tick to run this event on
   */
  uint32_t m_scheduled_tick;

}; // struct Scheduled_event

/**
 * @brief Physical attributes for an entity with a body
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
  using Scheduled_events = std::queue<std::shared_ptr<his_gen::Event_base>>;

  /**
   * @brief Schedule an event to run on the next tick
   * @param event_to_schedule
   */
  void Schedule_event(std::shared_ptr<Event_base> event_to_schedule);

  /**
   * @brief Schedule an event to run during `tick_to_run` tick
   * @param event_to_schedule The event to schedule
   * @param tick_to_run The tick to run the event in
   */
  void Schedule_distant_event(std::shared_ptr<Event_base> event_to_schedule,
                              uint32_t tick_to_run);

  /**
   * @brief Return the next event, and remove it from the schedule
   * @return A pointer to the next event
   */
  std::shared_ptr<Event_base> Handle_next_event();

  /**
   * @brief Get_all_scheduled_events
   * @return All scheduled events
   */
  Scheduled_events Get_all_scheduled_events() const { return m_scheduled_events; }

  /**
   * @brief More_events_to_run
   * @return True if there are more events to run, otherwise false.
   */
  bool More_events_to_run();

  /**
   * @brief Merge all scheduled events from another instance of this class
   * into this one.
   * @param scheduler_to_merge_into_this The other scheduler instance to
   * merge.
   */
  void Merge_scheduled_events(Event_scheduler scheduler_to_merge);

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

}; // class Event_scheduler
}  // namespace his_gen

#endif // EVENT_SCHEDULER_H
