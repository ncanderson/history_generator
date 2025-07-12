/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef INITIATED_REVOLT_EVENT_H
#define INITIATED_REVOLT_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Initiated_Revolt_event
 * @brief Represents the initiated_revolt event
 */
class Initiated_Revolt_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Initiated_Revolt_event();

  /**
   * @brief Virtual destructor
   */
  ~Initiated_Revolt_event() override;

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

#endif  // INITIATED_REVOLT_EVENT_H
