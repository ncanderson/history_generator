/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef SEEK_PARTNER_EVENT_H
#define SEEK_PARTNER_EVENT_H

// Standard libs
#include <memory>
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
    Seek_partner_event(std::shared_ptr<his_gen::Entity_base>& entity)
        :
        Event_base(his_gen::EEvent_type::EEVENT_TYPE_Seek_partner, "dummy", entity) {}

    void initialize_event() override {}
    void run_event() override {}
    void conclude_event() override {}
    std::vector<std::shared_ptr<Event_base>> get_next_steps() const override {return {};}
//  /**
//   * @brief Constructor
//   * @param triggering_entity The entity driving this event
//   */
//  Seek_partner_event(std::shared_ptr<Entity_base>& triggering_entity);

//   /**
//    * Getters and setters
//    */
//   // TODO

// //protected:
  // /**
  //  * @brief Event initialization logic
  //  */
  // void initialize_event() override;

  // /**
  //  * @brief Event execution logic
  //  */
  // void run_event() override;

  // /**
  //  * @brief Event conclusion logic
  //  */
  // void conclude_event() override;

  // /**
  //  * @brief Determines follow-on events
  //  * @return A vector of shared_ptrs to follow-on events
  //  */
  // std::vector<std::shared_ptr<Event_base>> get_next_steps() const override;

// private:

}; // class Seek_partner_event
}  // namespace his_gen

#endif  // SEEK_PARTNER_EVENT_H
