/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef MARRIAGE_EVENT_H
#define MARRIAGE_EVENT_H

// Standard libs

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @brief Represents the 'marriage' event
 */
class Marriage_event : public Event_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   * @param triggering_entity The entity driving this event
   * @parma current_tick The current tick
   */
  Marriage_event(std::shared_ptr<his_gen::Entity_base>& triggering_entity,
                 int64_t current_tick);

  /**
   * @brief Destructor
   */
  ~Marriage_event(){}

  /**
   * @brief Run
   * @param entities
   * @param entity_relationships
   * @param event_scheduler
   */
  void Run(his_gen::Entities& entities,
           his_gen::Entity_relationships& entity_relationships,
           Event_scheduler& event_scheduler) override;

  /**
   * @brief The list of possible next events
   * @return An unordered set of the possible next events
   */
  const std::unordered_set<his_gen::EEvent_type>& Get_possible_next_events() const override
  {
    return m_possible_next_events;
  }

protected:
  // Attributes

  // Implementation
  /**
   * @brief Schedule the next event
   * @param event_scheduler The event scheduler instance to use for scheduling
   */
  void schedule_next_event(Event_scheduler& event_scheduler) override;

private:
  // Attributes

  // Implementation
  /**
   * @brief Static list of all possible next events that could be triggered from this event.
   */
  static const std::unordered_set<his_gen::EEvent_type> m_possible_next_events;

};
}

#endif
