/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef MARRIED_EVENT_H
#define MARRIED_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Married_event
 * @brief Represents the married event
 */
class Married_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Married_event();

  /**
   * @brief Virtual destructor
   */
  ~Married_event() override;

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

}; // class Married_event
}  // namespace his_gen

#endif  // MARRIED_EVENT_H
