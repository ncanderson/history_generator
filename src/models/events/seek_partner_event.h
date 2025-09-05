/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef SEEK_PARTNER_EVENT_H
#define SEEK_PARTNER_EVENT_H

// Standard libs
#include <memory>
#include <vector>

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
