/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/events/social_scandal_event.h>
#include <models/entities/entity_base.h>

///////////////////////////////////////////////////////////////////////

REGISTER_POLYMORPHIC_TYPE(his_gen::Event_base, his_gen::Social_scandal_event)

///////////////////////////////////////////////////////////////////////

his_gen::Social_scandal_event::Social_scandal_event(std::shared_ptr<Entity_base>& triggering_entity,
                                                    int64_t current_tick,
                                                    his_gen::Generated_history& history_of_the_world,
                                                    const boost::uuids::uuid triggering_event_id)
  :
  Event_base(his_gen::EEvent_type::EEVENT_TYPE_Social_scandal,
             triggering_entity->Get_entity_id(),
             current_tick,
             history_of_the_world,
             triggering_event_id)
{ }

//////////////////////////////////////////////////////////////////////

void his_gen::Social_scandal_event::Run(Event_scheduler& event_scheduler)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Social_scandal_event::schedule_next_event(Event_scheduler& event_scheduler)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
