/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef ESTABLISHED_LAIR_EVENT_H
#define ESTABLISHED_LAIR_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Established_Lair_event
 * @brief Represents the established_lair event
 */
class Established_lair_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Established_lair_event();

  /**
   * @brief Virtual destructor
   */
  ~Established_lair_event() override;

protected:
  /**
   * @brief Event initialization logic
   */
  void initialize_event() override;

  /**
   * @brief Event execution logic
   */
  void run_event() override;

  /**
   * @brief Event conclusion logic
   */
  void conclude_event() override;

  /**
   * @brief Determines follow-on events
   * @return A vector of unique_ptrs to follow-on events
   */
  std::vector<std::unique_ptr<Event_base>> get_next_steps() const override;

}; // class Established_lair_event
}  // namespace his_gen

#endif  // ESTABLISHED_LAIR_EVENT_H
