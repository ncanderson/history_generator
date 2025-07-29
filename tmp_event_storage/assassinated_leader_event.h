/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef ASSASSINATED_LEADER_EVENT_H
#define ASSASSINATED_LEADER_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Assassinated_Leader_event
 * @brief Represents the assassinated_leader event
 */
class Assassinated_leader_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Assassinated_leader_event();

  /**
   * @brief Virtual destructor
   */
  ~Assassinated_leader_event() override;

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

}; // class Assassinated_leader_event
}  // namespace his_gen

#endif  // ASSASSINATED_LEADER_EVENT_H
