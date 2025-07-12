/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef ENACTED_POLICY_EVENT_H
#define ENACTED_POLICY_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Enacted_Policy_event
 * @brief Represents the enacted_policy event
 */
class Enacted_policy_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Enacted_policy_event();

  /**
   * @brief Virtual destructor
   */
  ~Enacted_policy_event() override;

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

}; // class Enacted_policy_event
}  // namespace his_gen

#endif  // ENACTED_POLICY_EVENT_H
