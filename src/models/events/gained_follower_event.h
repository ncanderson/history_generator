/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef GAINED_FOLLOWER_EVENT_H
#define GAINED_FOLLOWER_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Gained_Follower_event
 * @brief Represents the gained_follower event
 */
class Gained_Follower_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Gained_Follower_event();

  /**
   * @brief Virtual destructor
   */
  ~Gained_Follower_event() override;

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

#endif  // GAINED_FOLLOWER_EVENT_H
