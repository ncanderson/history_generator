/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/courtship_event.h>
#include <models/entities/entity_base.h>

///////////////////////////////////////////////////////////////////////

using er = his_gen::Entity_relationship;
REGISTER_POLYMORPHIC_TYPE(his_gen::Event_base, his_gen::Courtship_event)

///////////////////////////////////////////////////////////////////////

his_gen::Courtship_event::Courtship_event(std::shared_ptr<Entity_base>& triggering_entity,
                                          int64_t current_tick)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Courtship,
             triggering_entity,
             current_tick)
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::Run(his_gen::Entities& entities,
                                   his_gen::Entity_relationships& entity_relationships,
                                   Event_scheduler& event_scheduler)
{
  // The entity that triggered the event
  std::shared_ptr<his_gen::Entity_base> triggering_entity = Get_triggering_entity();
  // The targets of this event
  std::vector<std::shared_ptr<his_gen::Entity_base>> target_entities = get_target_entities(entities);

  for(std::shared_ptr<his_gen::Entity_base>& target_entity : target_entities)
  {

  }

  /**
   * Possible outcomes:
   * Reproduction
   */

  // TODO: Refactor this stuff into the base class I think, since there is boilerplate
  // bookeeping that we have now

  //// Add event target
  //Add_target(it);

  // Mark the internal flag so caller can know if this event did anything we care about
  meaningful_change_occurred(true);

  // Increment the event counter for this entity, allowing it to decide
  // if future events of this type are allowed
  triggering_entity->Increment_events_count(m_event_type);

  // Set the tick on the entity, so it won't be selected again this loop
  triggering_entity->Set_last_event_triggered(m_event_tick);

  // Schedule the next event
  schedule_next_event(event_scheduler);

  // It's done
  m_is_complete = true;
}

///////////////////////////////////////////////////////////////////////

void his_gen::Courtship_event::schedule_next_event(Event_scheduler& event_scheduler)
{
  /**
   * Possible outcomes:
   *
   * Another event
   * Reproduction
   * More courtship
   * Social Scandal
   * Secret Affair
   * Elopement
   * Marriage
   * Abuse / Toxic Relationship
   * Change in relationship, to:
   *   - breakup
   *   - mentorship or power dynamic
   *   - platonic/close friend
   *   - rivalry/jealousy
   *   - unrequited love/longing
   *   - abandonment/ghosting
   */
}

///////////////////////////////////////////////////////////////////////
