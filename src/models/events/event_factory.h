/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

// Standard libs
#include <memory>

// JSON

// Application files
#include <defs/history_generator_defs.h>
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @brief Factory for creating events from event type enumerations
 */
class Event_factory
{
public:
  // Attributes

  // Implementation
  Event_factory();

  /**
   * @brief Create and event from it's associated enumeration
   * @param event_type The enumerated event type
   * @return A pointer to Event_base, holding the instantiated derived event type
   */
  std::shared_ptr<his_gen::Event_base> Create_event(his_gen::EEvent_type event_type);

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Event_factory
}  // namespace his_gen

#endif // EVENT_FACTORY_H
