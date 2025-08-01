#ifndef DUMMY_EVENT_H
#define DUMMY_EVENT_H

#include "event_base.h"

namespace his_gen
{
class Dummy_event : public Event_base
{
public:
    Dummy_event(std::shared_ptr<his_gen::Entity_base>& entity)
        : Event_base(his_gen::EEvent_type::EEVENT_TYPE_Seek_partner, "dummy", entity) {}

    void initialize_event() override {}
    void run_event() override {}
    void conclude_event() override {}
    std::vector<std::shared_ptr<Event_base>> get_next_steps() const override {return {};}
};
}

#endif // DUMMY_EVENT_H
