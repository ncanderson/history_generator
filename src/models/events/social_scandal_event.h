/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef SOCIAL_SCANDAL_EVENT_H
#define SOCIAL_SCANDAL_EVENT_H

// Standard libs

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @brief Represents the 'social scandal' event
 */
class Social_scandal_event : public Event_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   * @param triggering_entity The entity driving this event
   * @parma current_tick The current tick
   */
  Social_scandal_event(std::shared_ptr<his_gen::Entity_base>& triggering_entity,
                       int64_t current_tick);

  /**
   * @brief Destructor
   */
  ~Social_scandal_event (){}

  /**
   * @brief Run
   * @param entities
   * @param entity_relationships
   * @param event_scheduler
   */
  void Run(his_gen::Entities& entities,
           his_gen::Entity_relationships& entity_relationships,
           Event_scheduler& event_scheduler);

  /**
   * Getters and setters
   */
  // TODO

protected:
  // Attributes

  // Implementation
  void schedule_next_event(Event_scheduler& event_scheduler);

private:
  // Attributes

  // Implementation

};
}

#endif
