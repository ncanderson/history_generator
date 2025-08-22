/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/seek_partner_event.h>
#include <models/entities/entity_base.h>

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
        // Add the target to this event's vector of targets if there is mutual attraction
        Add_target(it);
        meaningful_change_occurred(true);
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
  // NOOP
}

///////////////////////////////////////////////////////////////////////
