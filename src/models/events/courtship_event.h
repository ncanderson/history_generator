/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef COURTSHIP_EVENT_H
#define COURTSHIP_EVENT_H

// Standard libs

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @brief Represents the 'courtship' event
 */
class Courtship_event : public Event_base
{
public:

  /**
   * @brief Constructor
   * @param triggering_entity The entity driving this event
   * @parma current_tick The current tick
   */
  Courtship_event(std::shared_ptr<his_gen::Entity_base>& triggering_entity,
                  int64_t current_tick);

  /**
   * @brief Destructor
   */
  ~Courtship_event(){}

  /**
   * @brief Run
   * @param entities
   * @param entity_relationships
   * @param event_scheduler
   */
  void Run(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
           Entity_relationships& entity_relationships,
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

}; // class Courtship_event
}  // namespace his_gen

#endif  // COURTSHIP_EVENT_H
