/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef SEEK_PARTNER_EVENT_H
#define SEEK_PARTNER_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Seek_partner_event
 * @brief Represents the 'seek partner' event
 */
class Seek_partner_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Seek_partner_event(const std::string& name);

  /**
   * @brief Virtual destructor
   */
  ~Seek_partner_event() override;

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

}; // class Seek_partner_event
}  // namespace his_gen

#endif  // SEEK_PARTNER_EVENT_H
