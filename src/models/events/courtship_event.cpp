/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/courtship_event.h>

///////////////////////////////////////////////////////////////////////

using attrs = his_gen::Attribute_enums::EPersonality;
using Rel_matrix = his_gen::dice::Transition_matrix<his_gen::ERelationship_type>;

REGISTER_POLYMORPHIC_TYPE(his_gen::Event_base, his_gen::Courtship_event)

// Definition of possible next events
const std::unordered_set<his_gen::EEvent_type> his_gen::Courtship_event::m_possible_next_events = {
  EEVENT_TYPE_Courtship,
  EEVENT_TYPE_Elopement,
  EEVENT_TYPE_Marriage,
  EEVENT_TYPE_Reproduce,
  EEVENT_TYPE_Secret_affair,
  EEVENT_TYPE_Social_scandal,
  EEVENT_TYPE_Toxic_relationship
};

// Definition of possible relationship changes
const his_gen::Courtship_event::Relationship_transition_pattern his_gen::Courtship_event::m_relationship_transition_map {
  // Lover
  {
    his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Lover,
    his_gen::dice::Transition_drivers<attrs>({attrs::EPERSONALITY_Romantic,
                                              attrs::EPERSONALITY_Flirtatious,
                                              attrs::EPERSONALITY_Amiable,
                                              attrs::EPERSONALITY_Sociable,
                                              attrs::EPERSONALITY_Compassionate},
                                             {attrs::EPERSONALITY_Avoidant,
                                              attrs::EPERSONALITY_Reserved,
                                              attrs::EPERSONALITY_Chaste})
  },
  // Breakup
  {
      his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Breakup,
      his_gen::dice::Transition_drivers<attrs>({attrs::EPERSONALITY_Aggressive,
                                                attrs::EPERSONALITY_Argumentative,
                                                attrs::EPERSONALITY_Cruel,
                                                attrs::EPERSONALITY_Resentful,
                                                attrs::EPERSONALITY_Avoidant},
                                               {attrs::EPERSONALITY_Forgiving,
                                                attrs::EPERSONALITY_Compassionate,
                                                attrs::EPERSONALITY_Amiable})
  },
  // Platonic / Close friend
  {
      his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Friendship,
      his_gen::dice::Transition_drivers<attrs>({attrs::EPERSONALITY_Amiable,
                                                attrs::EPERSONALITY_Sociable,
                                                attrs::EPERSONALITY_Compassionate,
                                                attrs::EPERSONALITY_Kind,
                                                attrs::EPERSONALITY_Witty},
                                               {attrs::EPERSONALITY_Cruel,
                                                attrs::EPERSONALITY_Aggressive,
                                                attrs::EPERSONALITY_Selfish})
  },
  // Rivalry / Jealousy
  {
      his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Rivalry,
      his_gen::dice::Transition_drivers<attrs>({attrs::EPERSONALITY_Jealous,
                                                attrs::EPERSONALITY_Ambitious,
                                                attrs::EPERSONALITY_Proud,
                                                attrs::EPERSONALITY_Argumentative,
                                                attrs::EPERSONALITY_Aggressive},
                                               {attrs::EPERSONALITY_Humble,
                                                attrs::EPERSONALITY_Cooperative,
                                                attrs::EPERSONALITY_Forgiving})
  },
  // Unrequited love / Longing
  {
      his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Unrequited,
      his_gen::dice::Transition_drivers<attrs>({attrs::EPERSONALITY_Romantic,
                                                attrs::EPERSONALITY_Reserved,
                                                attrs::EPERSONALITY_Avoidant,
                                                attrs::EPERSONALITY_Pragmatic},
                                               {attrs::EPERSONALITY_Frank,
                                                attrs::EPERSONALITY_Aggressive,
                                                attrs::EPERSONALITY_Flirtatious})
  },
  // Abandonment / Ghosting
  {
      his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Abandonment,
      his_gen::dice::Transition_drivers<attrs>({attrs::EPERSONALITY_Avoidant,
                                                attrs::EPERSONALITY_Evasive,
                                                attrs::EPERSONALITY_Selfish,
                                                attrs::EPERSONALITY_Cruel,
                                                attrs::EPERSONALITY_Pragmatic},
                                               {attrs::EPERSONALITY_Compassionate,
                                                attrs::EPERSONALITY_Forgiving,
                                                attrs::EPERSONALITY_Cooperative})
  }
};

///////////////////////////////////////////////////////////////////////

his_gen::Courtship_event::Courtship_event(std::shared_ptr<Entity_base>& triggering_entity,
                                          int64_t current_tick)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Courtship,
             triggering_entity->Get_entity_id(),
             current_tick),
  m_relationship_transition_matrix(),
  m_trans_matrix_bounds(0, 1)
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::Run(his_gen::Entities& entities,
                                   his_gen::Entity_relationships& entity_relationships,
                                   Event_scheduler& event_scheduler)
{

  //need to have a field for triggering events, since if we modify a relationship
  //for an event, we need to know the relationship that should change


//  // The entity that triggered the event
//  std::shared_ptr<his_gen::Entity_base> triggering_entity = Get_triggering_entity();
//  // The targets of this event
//  std::vector<std::shared_ptr<his_gen::Entity_base>> target_entities = get_target_entities(entities);
//
//  for(std::shared_ptr<his_gen::Entity_base>& target_entity : target_entities)
//  {
//
//  }
//
//
//
//
//
//
//  // TODO: Refactor this stuff into the base class I think, since there is boilerplate
//  // bookeeping that we have now
//
//  //// Add event target
//  //Add_target(it);
//
//  // Mark the internal flag so caller can know if this event did anything we care about
//  meaningful_change_occurred(true);
//
//  // Increment the event counter for this entity, allowing it to decide
//  // if future events of this type are allowed
//  triggering_entity->Increment_events_count(m_event_type);
//
//  // Set the tick on the entity, so it won't be selected again this loop
//  triggering_entity->Set_last_event_triggered(m_event_tick);
//
//  // Schedule the next event
//  schedule_next_event(event_scheduler);
//
//  // It's done
//  m_is_complete = true;
}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::Visit_entity(Entity_sentient& sentient)
{
  define_relationship_matrix(sentient);
}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::schedule_next_event(Event_scheduler& event_scheduler)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::define_relationship_matrix(const Entity_sentient& triggering_entity)
{
  // Iterate over relationship transition map, and discard the values (for now)
  for(const auto& [current_state, _] : m_relationship_transition_map)
  {
    // Running total of a row's weights
    double row_sum = 0.0;

    // Temporary map to hold unnormalized weights
    std::map<ERelationship_type, double> weights;

    // Inner loop to build the full matrix for the 'current_state'
    for(const auto& [next_state, drivers] : m_relationship_transition_map)
    {
      // base weight, the baseline chance for this relationship
      double weight = 1.0;

      // Add positive influence, checking the entity for all personality traits
      // relevant to this relationship
      for (auto attr : drivers.m_positive_drivers)
      {
        weight += static_cast<double>(triggering_entity.Get_personality().Get_entity_attribute_value(attr)) / 100.0;
      }

      // Subtract negative influence, checking the entity for all personality traits
      // relevant to this relationship
      for (auto attr : drivers.m_negative_drivers)
      {
        weight -= static_cast<double>(triggering_entity.Get_personality().Get_entity_attribute_value(attr)) / 100.0;
      }

      // Clamp weight to avoid negative or zero
      m_trans_matrix_bounds.Enforce(weight);

      // Cache the fully calculated weights
      weights[next_state] = weight;

      // Get the running total of all weights
      row_sum += weight;
    }

    // Normalize the row so the full row will add up to 100%
    for (auto& [next_state, weight] : weights)
    {
      m_relationship_transition_matrix[current_state][next_state] = weight / row_sum;
    }
  }
}

///////////////////////////////////////////////////////////////////////
