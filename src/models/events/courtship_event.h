/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef COURTSHIP_EVENT_H
#define COURTSHIP_EVENT_H

// Standard libs

// Application files
#include <models/events/event_base.h>
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
   * @brief Constructor
   * @param triggering_entity The entity driving this event
   * @parma current_tick The current tick
   */
  Courtship_event(std::shared_ptr<Entity_base>&  triggering_entity,
                  int64_t current_tick);

  /**
   * @brief Destructor
   */
  ~Courtship_event(){}

  /**
   * @brief Run
   * @param entities
   * @param entity_relationships
   * @param event_scheduler
   */
  void Run(his_gen::Entities& entities,
           his_gen::Entity_relationships& entity_relationships,
           Event_scheduler& event_scheduler) override;

  /**
   * @brief The list of possible next events
   * @return An unordered set of the possible next events
   */
  const std::unordered_set<his_gen::EEvent_type>& Get_possible_next_events() const override
  {
    return m_possible_next_events;
  }

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
  /**
   * The pattern this event will use to define each entity's transition matrix
   * It is a map that uses ERelationship_type as the key, and an instance of the
   * templated helper struct Transition_drivers as the value. That struct
   * has a vector positive and negative drivers, which are used to construct
   * the likelihood that the ERelationship_type will be the next type selected.
   */
  using Relationship_transition_pattern = his_gen::dice::Transition_pattern<ERelationship_type, Attribute_enums::EPersonality>;

  // Attributes
  /**
   * @brief Enforcer of min/max values for the transition matrix rows
   */
  Bounds m_trans_matrix_bounds;

  /**
   * @brief Static list of all possible next events that could be triggered from this event.
   */
  static const std::unordered_set<his_gen::EEvent_type> m_possible_next_events;

  /**
   * @brief Transition matrix for determining new relationships
   */
  static const Relationship_transition_pattern m_relationship_transition_map;

  /**
   * @brief The relationship transition matrix for this entity
   */
  dice::Transition_matrix<ERelationship_type> m_relationship_transition_matrix;

  // Implementation
  /**
   * @brief Use the triggering entity's attributes to build the full relationship
   * transition matrix
   * @details This function will iterate over m_relationship_transition_map, a structure
   * containing the possible next relationships, and the personality traits
   * positiviely and negatively impacting the likelihood that that relationship is
   * selected next. The end result will be a fully populated relationship transition matrix
   * specific to this entity and event.
   * @param triggering_entity The entity triggering this event
   */
  void define_relationship_matrix(const Entity_sentient& triggering_entity);

};
}

#endif
