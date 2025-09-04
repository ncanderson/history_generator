/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/seek_partner_event.h>
#include <models/entities/entity_base.h>
#include <utils/event_scheduler.h>

///////////////////////////////////////////////////////////////////////

using er = his_gen::Entity_relationship;
REGISTER_POLYMORPHIC_TYPE(his_gen::Event_base, his_gen::Seek_partner_event)

///////////////////////////////////////////////////////////////////////

his_gen::Seek_partner_event::Seek_partner_event(std::shared_ptr<Entity_base>& triggering_entity,
                                                int64_t current_tick)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Seek_partner,
             triggering_entity,
             current_tick)
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Seek_partner_event::Run(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                                      Entity_relationships& entity_relationships,
                                      Event_scheduler& event_scheduler)
{
  // Check for entity attraction
  std::vector<std::pair<std::shared_ptr<his_gen::Entity_base>,
                        std::shared_ptr<his_gen::Entity_base>>> pairs;

  std::shared_ptr<his_gen::Entity_base> triggering_entity = Get_triggering_entity();

  // Loop through all entities
  for(auto& it : entities)
  {
    // Only compare entities that are the same type
    if(triggering_entity->Get_entity_type() != it->Get_entity_type())
    {
      // TODO: figure out how to do stuff like have trolls be attracted to
      // people and stuff.
      continue;
    }

    // Check the attraction of the triggering entity against this iteration
    if(triggering_entity->Is_attracted(it))
    {
      // If this entity is attracted to another entity, check for mutual attraction
      if(it->Is_attracted(triggering_entity))
      {
        // TODO: Refactor this stuff into the base class I think, since there is boilerplate
        // bookeeping that we have now

        // Add the target to this event's vector of targets if there is mutual attraction
        Add_target(it);
        // Mark the internal flag so caller can know if this event did anything we care about
        meaningful_change_occurred(true);
        // Increment the event counter for this entity, allowing it to decide
        // if future events of this type are allowed
        it->Increment_events_count(m_event_type);
        // Set the tick on the entity, so it won't be selected again this loop
        triggering_entity->Set_last_event_triggered(m_event_tick);

        // Create the new relationship for these entities
        er::Entity_relationship_ptr new_relationship = er::Entity_relationship_factory(triggering_entity,
                                                                                       it,
                                                                                       his_gen::ERELATIONSHIP_TYPE_Lover);

        // Add the new relationship to the generated history reference
        entity_relationships[new_relationship->Get_entity_relationship_id()] = new_relationship;

        // Schedule the next event
        schedule_next_event(event_scheduler);
        return;
      }
      else
      {
        continue;
      }
    }
  }
  // It's done
  m_is_complete = true;
}

///////////////////////////////////////////////////////////////////////

void his_gen::Seek_partner_event::schedule_next_event(Event_scheduler& event_scheduler)
{
  event_scheduler.Schedule_event(m_triggering_entity,
                                 Get_target_ids(),
                                 his_gen::EEvent_type::EEVENT_TYPE_Courtship,
                                 m_event_tick++);
}

///////////////////////////////////////////////////////////////////////
