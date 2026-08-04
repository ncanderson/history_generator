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
using court = his_gen::Courtship_event;

REGISTER_POLYMORPHIC_TYPE(his_gen::Event_base, his_gen::Courtship_event)

///////////////////////////////////////////////////////////////////////

// Definition of possible next events
const court::Event_transition_pattern court::m_event_transition_pattern {
  {
    EEVENT_TYPE_Courtship,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Romantic,
                                        attrs::EPERSONALITY_Flirtatious,
                                        attrs::EPERSONALITY_Sociable,
                                        attrs::EPERSONALITY_Amiable,
                                        attrs::EPERSONALITY_Brave},
                                       {attrs::EPERSONALITY_Avoidant,
                                        attrs::EPERSONALITY_Reserved,
                                        attrs::EPERSONALITY_Chaste,
                                        attrs::EPERSONALITY_Cowardly})
  },
  {
    EEVENT_TYPE_Elopement,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Romantic,
                                        attrs::EPERSONALITY_Rash,
                                        attrs::EPERSONALITY_Brave,
                                        attrs::EPERSONALITY_Decisive,
                                        attrs::EPERSONALITY_Progressive},
                                       {attrs::EPERSONALITY_Cowardly,
                                        attrs::EPERSONALITY_Indecisive,
                                        attrs::EPERSONALITY_Pragmatic,
                                        attrs::EPERSONALITY_Conservative,
                                        attrs::EPERSONALITY_Reserved})
  },
  {
    EEVENT_TYPE_Marriage,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Romantic,
                                        attrs::EPERSONALITY_Cooperative,
                                        attrs::EPERSONALITY_Decisive,
                                        attrs::EPERSONALITY_Diligent,
                                        attrs::EPERSONALITY_Compassionate,
                                        attrs::EPERSONALITY_Pragmatic},
                                       {attrs::EPERSONALITY_Avoidant,
                                        attrs::EPERSONALITY_Indecisive,
                                        attrs::EPERSONALITY_Selfish,
                                        attrs::EPERSONALITY_Deceitful,
                                        attrs::EPERSONALITY_Difficult})
  },
  {
      EEVENT_TYPE_Reproduce,
      his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Lustful,
                                          attrs::EPERSONALITY_Romantic,
                                          attrs::EPERSONALITY_Compassionate,
                                          attrs::EPERSONALITY_Content,
                                          attrs::EPERSONALITY_Conservative},
                                         {attrs::EPERSONALITY_Chaste,
                                          attrs::EPERSONALITY_Avoidant,
                                          attrs::EPERSONALITY_Selfish,
                                          attrs::EPERSONALITY_Pragmatic})
  },
  {
    EEVENT_TYPE_Secret_affair,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Lustful,
                                        attrs::EPERSONALITY_Flirtatious,
                                        attrs::EPERSONALITY_Deceitful,
                                        attrs::EPERSONALITY_Evasive,
                                        attrs::EPERSONALITY_Rash,
                                        attrs::EPERSONALITY_Selfish},
                                       {attrs::EPERSONALITY_Chaste,
                                        attrs::EPERSONALITY_Honest,
                                        attrs::EPERSONALITY_Frank,
                                        attrs::EPERSONALITY_Thoughtful,
                                        attrs::EPERSONALITY_Compassionate})
  },
  {
    EEVENT_TYPE_Social_scandal,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Extravagant,
                                        attrs::EPERSONALITY_Extremist,
                                        attrs::EPERSONALITY_Rash,
                                        attrs::EPERSONALITY_Lustful,
                                        attrs::EPERSONALITY_Proud},
                                       {attrs::EPERSONALITY_Reserved,
                                        attrs::EPERSONALITY_Thoughtful,
                                        attrs::EPERSONALITY_Thrifty,
                                        attrs::EPERSONALITY_Humble,
                                        attrs::EPERSONALITY_Placid})
  },
  {
    EEVENT_TYPE_Toxic_relationship,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Aggressive,
                                        attrs::EPERSONALITY_Argumentative,
                                        attrs::EPERSONALITY_Cruel,
                                        attrs::EPERSONALITY_Jealous,
                                        attrs::EPERSONALITY_Resentful,
                                        attrs::EPERSONALITY_Difficult},
                                       {attrs::EPERSONALITY_Cooperative,
                                        attrs::EPERSONALITY_Amiable,
                                        attrs::EPERSONALITY_Compassionate,
                                        attrs::EPERSONALITY_Forgiving,
                                        attrs::EPERSONALITY_Flexible,
                                        attrs::EPERSONALITY_Placid})
  }
};

// Definition of possible relationship changes
const court::Relationship_transition_pattern court::m_relationship_transition_pattern {
  {
    ERELATIONSHIP_TYPE_Lover,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Romantic,
                                        attrs::EPERSONALITY_Flirtatious,
                                        attrs::EPERSONALITY_Amiable,
                                        attrs::EPERSONALITY_Sociable,
                                        attrs::EPERSONALITY_Compassionate},
                                       {attrs::EPERSONALITY_Avoidant,
                                        attrs::EPERSONALITY_Reserved,
                                        attrs::EPERSONALITY_Chaste})
  },
  {
    ERELATIONSHIP_TYPE_Breakup,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Aggressive,
                                        attrs::EPERSONALITY_Argumentative,
                                        attrs::EPERSONALITY_Cruel,
                                        attrs::EPERSONALITY_Resentful,
                                        attrs::EPERSONALITY_Avoidant},
                                       {attrs::EPERSONALITY_Forgiving,
                                        attrs::EPERSONALITY_Compassionate,
                                        attrs::EPERSONALITY_Amiable})
  },
  {
    ERELATIONSHIP_TYPE_Friendship,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Amiable,
                                        attrs::EPERSONALITY_Sociable,
                                        attrs::EPERSONALITY_Compassionate,
                                        attrs::EPERSONALITY_Kind,
                                        attrs::EPERSONALITY_Witty},
                                       {attrs::EPERSONALITY_Cruel,
                                        attrs::EPERSONALITY_Aggressive,
                                        attrs::EPERSONALITY_Selfish})
  },
  {
    ERELATIONSHIP_TYPE_Rivalry,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Jealous,
                                        attrs::EPERSONALITY_Ambitious,
                                        attrs::EPERSONALITY_Proud,
                                        attrs::EPERSONALITY_Argumentative,
                                        attrs::EPERSONALITY_Aggressive},
                                       {attrs::EPERSONALITY_Humble,
                                        attrs::EPERSONALITY_Cooperative,
                                        attrs::EPERSONALITY_Forgiving})
  },
  {
    ERELATIONSHIP_TYPE_Unrequited,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Romantic,
                                        attrs::EPERSONALITY_Reserved,
                                        attrs::EPERSONALITY_Avoidant,
                                        attrs::EPERSONALITY_Pragmatic},
                                       {attrs::EPERSONALITY_Frank,
                                        attrs::EPERSONALITY_Aggressive,
                                        attrs::EPERSONALITY_Flirtatious})
  },
  {
    ERELATIONSHIP_TYPE_Abandonment,
    his_gen::Transition_drivers<attrs>({attrs::EPERSONALITY_Avoidant,
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
                                          his_gen::Generated_history& history_of_the_world,
                                          const boost::uuids::uuid triggering_event_id)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Courtship,
             triggering_entity->Get_entity_id(),
             current_tick,
             history_of_the_world,
             triggering_event_id)
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::Run(Event_scheduler& event_scheduler)
{
  // Check the triggering event for an incoming relationship
  boost::uuids::uuid triggering_event_id = Get_triggering_event_id();

  // Get the entity we'll be working wtih
  std::shared_ptr<his_gen::Entity_base> triggering_entity = m_generated_history.Get_entities()[Get_triggering_entity_id()];

  // If we get a nil back from Get_triggering_event_id(), there won't be a previous relationship
  // to modify
  if(triggering_event_id != boost::uuids::nil_uuid())
  {
    // Get the event to work with
    std::shared_ptr<Event_base> trigger_notaro = m_generated_history.Get_event(Get_triggering_event_id());

    // For every relationship that was created in the previous event, check if it should change
    for(const auto& relationship_id : trigger_notaro->Get_relationship_ids())
    {
      std::shared_ptr<his_gen::Entity_relationship> rel = m_generated_history.Get_entity_relationship(relationship_id);

      // Check for relationship updates, changes to relationships mean meaningful change occurred
      meaningful_change_occurred(update_relationship_type(rel));
      if(Created_meaningful_change())
      {
        // Add event targets
        // This assumes that 'update_relationship' will forward any involved entity IDs from
        // the previous relationship to the new relationship. 'update_relationship' could be
        // refactored or overloaded to return a new relationshipo ID, if one is created, which
        // would allow this section here to pull the IDs of the full Generated_history, as this
        // section will break if the involved entities change from the previous relationship to here,
        // which shouldn't happen but if it did it would be tough to spot.
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
  Entities entities = m_generated_history.Get_entities();
  const Personality* entity_personality = entities[Get_triggering_entity_id()]->Get_personality();

  m_relationship_transition_matrix.Define_transition_matrix(m_relationship_transition_pattern,
                                                            entity_personality);
  m_event_transition_matrix.Define_transition_matrix(m_event_transition_pattern,
                                                     entity_personality);
}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::Visit_entity(Entity_deity& deity)
{
  Visit_entity(static_cast<Entity_sentient&>(deity));
}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::schedule_next_event(Event_scheduler& event_scheduler)
{
  // for(const his_gen::EEvent_type& event_type : m_possible_next_events)
  // {
    // these are the possible next event types
    // EEVENT_TYPE_Courtship,
    // EEVENT_TYPE_Elopement,
    // EEVENT_TYPE_Marriage,
    // EEVENT_TYPE_Reproduce,
    // EEVENT_TYPE_Secret_affair,
    // EEVENT_TYPE_Social_scandal,
    // EEVENT_TYPE_Toxic_relationship

    // I don't know why I put this here
    //switch(id)
    //his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Lover,
    //his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Breakup,
    //his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Friendship,
    //his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Rivalry,
    //his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Unrequited,
    //his_gen::ERelationship_type::ERELATIONSHIP_TYPE_Abandonment,
  // }
}

///////////////////////////////////////////////////////////////////////

// TODO: Move this into base? Or into Entity_relationship itself?
// TODO: Can this lead to no change, via randomly selecting the same next state? If that happens,
// does this function handle it gracefully?
bool his_gen::Courtship_event::update_relationship_type(std::shared_ptr<his_gen::Entity_relationship>& relationship)
{
  // Helper to cut down line length
  using er = his_gen::Entity_relationship;

  // Get the current relationship type
  const his_gen::ERelationship_type& rel = relationship->Get_relationship_type_enum();
  // Use functionality defined in the Transition_matrix class to roll for a relationship transition
  const std::optional<his_gen::ERelationship_type> next_type = m_relationship_transition_matrix.Roll_transition(rel);

  // If no transition:
  if(!next_type)
  {
    return false;
  }

  // Otherwise, end the previous relationship,
  relationship->End_date_relationship(m_event_tick);

  // Create the new relationship.
  std::shared_ptr<er> new_rel = er::Entity_relationship_factory(relationship->Get_entity_1(),
                                                                relationship->Get_entity_2(),
                                                                *next_type,
                                                                m_event_tick);

  // Register the new relationship.
  m_generated_history.Add_entity_relationship(new_rel);

  // Associate the relationship with this event.
  Add_relationship_id(new_rel->Get_entity_relationship_id());

  return true;
}

///////////////////////////////////////////////////////////////////////
