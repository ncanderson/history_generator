/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef SPLIT_FROM_GROUP_EVENT_H
#define SPLIT_FROM_GROUP_EVENT_H

// Standard libs
#include <memory>
#include <string>
#include <vector>

// Application files
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @class Split_From_Group_event
 * @brief Represents the split_from_group event
 */
class Split_from_group_event : public Event_base
{
public:
  /**
   * @brief Constructor sets the event name
   */
  Split_from_group_event();

  /**
   * @brief Virtual destructor
   */
  ~Split_from_group_event() override;

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

}; // class Split_from_group_event
}  // namespace his_gen

#endif  // SPLIT_FROM_GROUP_EVENT_H
