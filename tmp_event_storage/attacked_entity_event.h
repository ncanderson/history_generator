/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef ATTACKED_ENTITY_EVENT_H
#define ATTACKED_ENTITY_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Attacked_Entity_event
 * @brief Represents the attacked_entity event
 */
class Attacked_entity_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Attacked_entity_event();

  /**
   * @brief Virtual destructor
   */
  ~Attacked_entity_event() override;

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

}; // class Attacked_entity_event
}  // namespace his_gen

#endif  // ATTACKED_ENTITY_EVENT_H
