/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef SPREAD_INFLUENCE_EVENT_H
#define SPREAD_INFLUENCE_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Spread_Influence_event
 * @brief Represents the spread_influence event
 */
class Spread_Influence_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Spread_Influence_event();

  /**
   * @brief Virtual destructor
   */
  ~Spread_Influence_event() override;

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

}; // class Spread_Influence_event
}  // namespace his_gen

#endif  // SPREAD_INFLUENCE_EVENT_H
