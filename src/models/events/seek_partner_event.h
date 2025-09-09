/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef SEEK_PARTNER_EVENT_H
#define SEEK_PARTNER_EVENT_H

// Standard libs
#include <memory>
#include <unordered_set>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Seek_partner_event
 * @brief Represents the 'seek partner' event
 */
class Seek_partner_event : public Event_base
{
public:

  /**
   * @brief Constructor
   * @param triggering_entity The entity driving this event
   * @parma current_tick The current tick
   */
  Seek_partner_event(std::shared_ptr<his_gen::Entity_base>& triggering_entity,
                     int64_t current_tick);

  /**
   * @brief Destructor
   */
  ~Seek_partner_event(){}

  /**
   * @brief Run the event
   * @param entities The current set of entities, for check attraction
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
  /**
   * @brief Static list of all possible next events that could be triggered from this event.
   */
  static const std::unordered_set<his_gen::EEvent_type> m_possible_next_events;

  // Implementation

};
}

#endif
