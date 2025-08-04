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
   */
  Seek_partner_event(std::shared_ptr<his_gen::Entity_base>& triggering_entity);

  /**
   * @brief Destructor
   */
  ~Seek_partner_event(){}

  /**
   * @brief Run the event
   */
  void Run();

  /**
   * Getters and setters
   */
  // TODO

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Seek_partner_event
}  // namespace his_gen

#endif  // SEEK_PARTNER_EVENT_H
