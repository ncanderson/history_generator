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
 * @details This class provides methods for creating new events from types. It
 * cannot be instantiated.
 */
class Event_factory
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Deleted constructor to make this class non-instantiable
   */
  Event_factory() = delete;

  /**
   * @brief Deleted destructor to make this class non-instantiable
   */
  ~Event_factory() = delete;

  /**
   * @brief Create and event from it's associated enumeration
   * @param event_type The enumerated event type
   * @param triggering_entity The entity driving this event
   * @param current_tick The current generation tick
   * @return A pointer to Event_base, holding the instantiated derived event type
   */
  static std::shared_ptr<his_gen::Event_base> Create_event(his_gen::EEvent_type event_type,
                                                           std::shared_ptr<Entity_base>& triggering_entity,
                                                           uint64_t current_tick);

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Event_factory
}  // namespace his_gen

#endif // EVENT_FACTORY_H
