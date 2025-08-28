/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/reproduce_event.h>
#include <models/entities/entity_base.h>

///////////////////////////////////////////////////////////////////////

using er = his_gen::Entity_relationship;
REGISTER_POLYMORPHIC_TYPE(his_gen::Event_base, his_gen::Reproduce_event)

///////////////////////////////////////////////////////////////////////

his_gen::Reproduce_event::Reproduce_event(std::shared_ptr<Entity_base>& triggering_entity,
                                          int64_t current_tick)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Reproduce,
             triggering_entity,
             current_tick)
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Reproduce_event::Run(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                                   Entity_relationships& entity_relationships,
                                   Event_scheduler& event_scheduler)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Reproduce_event::schedule_next_event(Event_scheduler& event_scheduler)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
