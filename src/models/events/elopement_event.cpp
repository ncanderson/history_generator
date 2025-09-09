/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/elopement_event.h>
#include <models/entities/entity_base.h>

///////////////////////////////////////////////////////////////////////

REGISTER_POLYMORPHIC_TYPE(his_gen::Event_base, his_gen::Elopement_event)

// Definition of possible next events
const std::unordered_set<his_gen::EEvent_type> his_gen::Elopement_event::m_possible_next_events = {};

///////////////////////////////////////////////////////////////////////

his_gen::Elopement_event::Elopement_event(std::shared_ptr<Entity_base>& triggering_entity,
                                          int64_t current_tick)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Elopement,
             triggering_entity,
             current_tick)
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Elopement_event::Run(his_gen::Entities& entities,
                                   his_gen::Entity_relationships& entity_relationships,
                                   Event_scheduler& event_scheduler)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Elopement_event::schedule_next_event(Event_scheduler& event_scheduler)
{

}

///////////////////////////////////////////////////////////////////////
