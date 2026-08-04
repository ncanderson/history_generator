/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef COURTSHIP_EVENT_H
#define COURTSHIP_EVENT_H

// Standard libs

// Application files
#include <models/events/event_base.h>

#include <modules/transition_matrix.h>

#include <utils/dice_rolls.h>
#include <utils/bounds.h>

// Implementing entities
#include <models/entities/entity_sentient.h>
#include <models/entities/entity_deity.h>

namespace his_gen
{
/**
 * @brief Represents the 'courtship' event
 */
class Courtship_event : public Event_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Courtship_event
   * @param triggering_entity
   * @param current_tick
   * @param triggering_event_id
   */
  Courtship_event(std::shared_ptr<Entity_base>&  triggering_entity,
                  int64_t current_tick,
                  his_gen::Generated_history& history_of_the_world,
                  const boost::uuids::uuid triggering_event_id = boost::uuids::nil_uuid());

  /**
   * @brief Destructor
   */
  ~Courtship_event(){}

  /**
   * @brief Run
   * @param history_of_the_world
   * @param event_scheduler
   */
  void Run(Event_scheduler& event_scheduler) override;

  ///////////////////////////////////////////////////////////////////////
  // Visitors

  /**
   * @brief Visitor for sentient entities
   * @param sentient The entity in question
   */
  void Visit_entity(Entity_sentient& sentient) override;

  /**
   * @brief Deities (any any other entity derived from 'sentient') require
   * an overload, but just re-route to the Entity_sentient call
   * @param deity The deity in question
   */
  void Visit_entity(Entity_deity& deity) override
  {
    Visit_entity(static_cast<Entity_sentient&>(deity));
  }

protected:
  // Attributes

  // Implementation
  /**
   * @brief Schedule the next event
   * @param event_scheduler The event scheduler instance to use for scheduling
   */
  void schedule_next_event(Event_scheduler& event_scheduler) override;

private:
  // Attributes
  /**
   * @brief Transition matrix for determining new relationships
   */
  static const Relationship_transition_pattern m_relationship_transition_pattern;

  /**
   * @brief The relationship transition matrix for this event
   */
  his_gen::Transition_matrix<ERelationship_type> m_relationship_trans_matrix;

  /**
   * @brief Static list of all possible next events that could be triggered from this event.
   */
  static const Event_transition_pattern m_event_transition_pattern;

  /**
   * @brief The event transition matrix for this event
   */
  his_gen::Transition_matrix<EEvent_type> m_event_trans_matrix;

  // Implementation
  /**
   * @brief update_relationship_type
   * @param relationship
   * @return
   */
  bool update_relationship_type(std::shared_ptr<his_gen::Entity_relationship>& relationship);

};
}

#endif
