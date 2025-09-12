/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/secret_affair_event.h>
#include <models/entities/entity_base.h>

///////////////////////////////////////////////////////////////////////

REGISTER_POLYMORPHIC_TYPE(his_gen::Event_base, his_gen::Secret_affair_event)

// Definition of possible next events
const std::unordered_set<his_gen::EEvent_type> his_gen::Secret_affair_event::m_possible_next_events = {};

///////////////////////////////////////////////////////////////////////

his_gen::Secret_affair_event::Secret_affair_event(std::shared_ptr<Entity_base>& triggering_entity,
                                                  int64_t current_tick,
                                                  const boost::uuids::uuid triggering_event_id)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Reproduce,
             triggering_entity->Get_entity_id(),
             current_tick,
             triggering_event_id)
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Secret_affair_event::Run(his_gen::Entities& entities,
                                       his_gen::Entity_relationships& entity_relationships,
                                       Event_scheduler& event_scheduler)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Secret_affair_event::schedule_next_event(Event_scheduler& event_scheduler)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
