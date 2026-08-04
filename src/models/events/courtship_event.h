/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef COURTSHIP_EVENT_H
#define COURTSHIP_EVENT_H

// Standard libs
#include <memory>

// Application files
#include <models/events/event_base.h>
#include <utils/bounds.h>

namespace his_gen
{

/**
 * Forward declarations
 */
class Entity_base;
class Entity_deity;
class Entity_sentient;
class Generated_history;

/**
 * @brief Represents the 'courtship' event
 * @details This event will use any relationships previously established and
 * potentially change them to a different relationship type, as well as
 * scheduling other events based on the course of this relationship's courtship.
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
   * @brief Visitor for sentient entities.
   * @details This function allows this event to perform the necessary initialization
   * of the the entities in question.
   * @param sentient The entity in question
   */
  void Visit_entity(Entity_sentient& sentient) override;

  /**
   * @brief Deities (any any other entity derived from 'sentient') require
   * an overload, but just re-route to the Entity_sentient call
   * @param deity The deity in question
   */
  void Visit_entity(Entity_deity& deity) override;

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
   * @brief Transition pattern used for determining the new transition matrix, defining the attributes
   * that will impact the chance of a specific next event.
   */
  static const Event_transition_pattern m_event_transition_pattern;

  /**
   * @brief Transition pattern used for determining the new transition matrix, defining the attributes
   * that will impact the chance of a specific next relationship.
   */
  static const Relationship_transition_pattern m_relationship_transition_pattern;

  // Implementation
  /**
   * @brief Use the triggering entity's attributes to build the full relationship
   * transition matrix
   * @details This function will iterate over m_relationship_transition_pattern, a structure
   * containing the possible next relationships, and the personality traits
   * positiviely and negatively impacting the likelihood that that relationship is
   * selected next. The end result will be a fully populated relationship transition matrix
   * specific to this entity and event.
   * @param triggering_entity The entity triggering this event
   */
  void define_relationship_matrix(const Entity_sentient& triggering_entity);

  /**
   * @brief Use the triggering entity's attributes to build the full event
   * transition matrix
   * @details This function will iterate over m_event_transition_pattern, a structure
   * containing the possible next events, and the personality traits
   * positiviely and negatively impacting the likelihood that that event is
   * selected next. The end result will be a fully populated event transition matrix
   * specific to this entity and event.
   * @param triggering_entity The entity triggering this event
   */
  void define_event_matrix(const Entity_sentient& triggering_entity);

  /**
   * @brief update_relationship_type
   * @param relationship The relationship that might be modified
   * @returns Returns true if a relationship was updated, otherwise false. This will allow
   * the event to track the overall status of 'something changed'.
   */
  bool update_relationship_type(std::shared_ptr<his_gen::Entity_relationship>& relationship);

};
}

#endif
