/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef INTERVENED_IN_WORLD_EVENT_H
#define INTERVENED_IN_WORLD_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Intervened_In_World_event
 * @brief Represents the intervened_in_world event
 */
class Intervened_in_world_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Intervened_in_world_event();

  /**
   * @brief Virtual destructor
   */
  ~Intervened_in_world_event() override;

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

}; // class Intervened_in_world_event
}  // namespace his_gen

#endif  // INTERVENED_IN_WORLD_EVENT_H
