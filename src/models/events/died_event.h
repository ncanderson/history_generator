/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef DIED_EVENT_H
#define DIED_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Died_event
 * @brief Represents the died event
 */
class Died_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Died_event();

  /**
   * @brief Virtual destructor
   */
  ~Died_event() override;

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
};
}  // namespace his_gen

#endif  // DIED_EVENT_H
