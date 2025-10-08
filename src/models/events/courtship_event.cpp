/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#include <models/events/courtship_event.h>

// Standard libs

// Application files
#include <models/relations/entity_relationship.h>

// Implementing entities
#include <models/entities/entity_sentient.h>
#include <models/entities/entity_deity.h>

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
                                          int64_t current_tick,
                                          const boost::uuids::uuid triggering_event_id)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Courtship,
             triggering_entity->Get_entity_id(),
             current_tick,
             triggering_event_id),
  m_trans_matrix_bounds(0, 1),
  m_relationship_transition_matrix()
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::Run(his_gen::Generated_history& history_of_the_world,
                                   Event_scheduler& event_scheduler)
{
  // Check the triggering event for an incoming relationship
  boost::uuids::uuid triggering_event_id = Get_triggering_event_id();

  // Get the entity we'll be working wtih
  std::shared_ptr<his_gen::Entity_base> triggering_entity = history_of_the_world.Get_entities()[Get_triggering_entity_id()];

  // If we get a nil back from Get_triggering_event_id(), there won't be a previous relationship
  // to modify
  if(triggering_event_id != boost::uuids::nil_uuid())
  {
    std::shared_ptr<Event_base> trigger_notaro = history_of_the_world.Get_event(Get_triggering_event_id());

    // For every relationship that was created in the previous event, check if it should change
    for(const auto& relationship_id : trigger_notaro->Get_relationship_ids())
    {
      std::shared_ptr<his_gen::Entity_relationship> rel = history_of_the_world.Get_entity_relationship(relationship_id);
      // Check for relationship updates, changes to relationships mean meaningful change occurred
      meaningful_change_occurred(update_relationship(rel, history_of_the_world));
      if(Created_meaningful_change())
      {
        // Add event targets
        // This assumes that 'update_relationship' will forward any involved entity IDs from
        // the previous relationship to the new relationship. 'update_relationship' could be
        // refactored or overloaded to return a new relationshipo ID, if one is created, which
        // would allow this section here to pull the IDs of the full Generated_history, as this
        // section will break if the involved entities change from the previous relationship to here.
        Add_event_target_id(rel->Get_entity_1()->Get_entity_id());
        Add_event_target_id(rel->Get_entity_2()->Get_entity_id());
      }
    }
  }
  else
  {
    // What happens here if there is no previous relationship? Should this even be allowed?
  }

  // TODO Only increment if meaningful change occurred?
  // Increment the event counter for this entity, allowing it to decide
  // if future events of this type are allowed
  triggering_entity->Increment_events_count(m_event_type);

  // TODO Only modify if meaningful change occurred?
  // Set the tick on the entity, so it won't be selected again this loop
  triggering_entity->Set_last_event_triggered(m_event_tick);

  // Schedule the next event
  schedule_next_event(event_scheduler);

  // It's done
  m_is_complete = true;
}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::Visit_entity(Entity_sentient& sentient)
{
  define_relationship_matrix(sentient);
}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::Visit_entity(Entity_deity& deity)
{
  Visit_entity(static_cast<Entity_sentient&>(deity));
}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::schedule_next_event(Event_scheduler& event_scheduler)
{
  // TODO
  // Use the relations
}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::define_relationship_matrix(const Entity_sentient& triggering_entity)
{
  // Iterate over relationship transition map, and discard the values (for now);
  // this will act on each possible next relationship
  for(const auto& [current_state, _] : m_relationship_transition_map)
  {
    // Running total of a row's weights
    double row_sum = 0.0;

    // Temporary map to hold unnormalized weights
    std::map<ERelationship_type, double> weights;

    // Inner loop to build the full matrix for the 'current_state', indicating
    // the likelihood of transition to the next state. This will use the 'drivers',
    // or the entity attributes that affect the chance of a next relationship.
    for(const auto& [next_state, drivers] : m_relationship_transition_map)
    {
      // base weight, the baseline chance for this relationship
      // TODO Set this in defs somewhere?
      double weight = 1.0;

      // Add positive influence, checking the entity for all personality traits
      // relevant to this relationship
      for (auto attr : drivers.m_positive_drivers)
      {
        weight += static_cast<double>(triggering_entity.Get_personality()
                                                       .Get_entity_attribute_value(attr)) / 100.0;
      }

      // Subtract negative influence, checking the entity for all personality traits
      // relevant to this relationship
      for (auto attr : drivers.m_negative_drivers)
      {
        weight -= static_cast<double>(triggering_entity.Get_personality()
                                                       .Get_entity_attribute_value(attr)) / 100.0;
      }

      // Enforce bounds
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

// TODO: Move this into base? Or into Entity_relationship itself?
// TODO: Can this lead to no change, via randomly selecting the same next state? If that happens,
// does this function handle it gracefully?
bool his_gen::Courtship_event::update_relationship(std::shared_ptr<his_gen::Entity_relationship>& relationship,
                                                   his_gen::Generated_history& history_of_the_world)
{
  // Get the row for the current relationship type
  auto row_it = m_relationship_transition_matrix.find(relationship->Get_relationship_type_enum());
  // Throw if not found
  if(row_it == m_relationship_transition_matrix.end())
  {
    throw std::runtime_error("No transition data for current relationship");
  }

  // Possible next relationships
  const auto& transitions = row_it->second;

  // Make the roll
  double roll = his_gen::dice::Make_a_roll<double>(1.0, 0.0);
  double cumulative = 0.0;

  // Iterate through the possible next relationships in the transition matrix.
  // With every iteration, add the probability from the matrix (which was defined
  // when the event was created based on entity attributes). There is a lazy evaluation here,
  // so the first possible next relationship will be returned.
  for(const auto& [next_type, probability] : transitions)
  {
    cumulative += probability;
    // i.e. we found the next relationship to transition to
    if(roll <= cumulative)
    {
      // End date previous relationship
      relationship->End_date_relationship(m_event_tick);

      // Make a new relationship; this will also update each entity with that relationship (via the factory)
      std::shared_ptr<his_gen::Entity_relationship> new_rel;
      new_rel = his_gen::Entity_relationship::Entity_relationship_factory(relationship->Get_entity_1(),
                                                                          relationship->Get_entity_2(),
                                                                          next_type,
                                                                          m_event_tick);
      // Add the new relationship to this event
      Add_relationship_id(new_rel->Get_entity_relationship_id());
      return true;
    }
  }

  // Nothing changed, return false
  return false;
}

///////////////////////////////////////////////////////////////////////
