/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef FORMED_ALLIANCE_EVENT_H
#define FORMED_ALLIANCE_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Formed_Alliance_event
 * @brief Represents the formed_alliance event
 */
class Formed_alliance_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Formed_alliance_event();

  /**
   * @brief Virtual destructor
   */
  ~Formed_alliance_event() override;

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

}; // class Formed_alliance_event
}  // namespace his_gen

#endif  // FORMED_ALLIANCE_EVENT_H
