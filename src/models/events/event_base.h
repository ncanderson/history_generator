/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef EVENT_BASE_H
#define EVENT_BASE_H

// Standard libs
#include <vector>
#include <memory>
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <defs/history_generator_defs.h>
#include <models/entities/entity_base.h>

// TODO Think a bit more about how this class manages the entities that it cares
// about. Only the ID is being deserialized in the from_json function, meaning
// that any events loaded from file/db will require an additional lookup to
// fully populate the pointer to that entity. In practice this might not matter,
// but if that becomes a requirement, more attention will be required.
namespace his_gen
{
class Event_base {
public:
    Event_base(EEvent_type type, const std::string& name, std::shared_ptr<Entity_base>& entity);
    virtual ~Event_base();                   // Not `= 0`!
    virtual void initialize_event();         // Not `= 0`
    virtual void run_event();                // Not `= 0`
    virtual void conclude_event();           // Not `= 0`
    virtual std::vector<std::shared_ptr<Event_base>> get_next_steps() const;
};
}

#endif // EVENT_BASE_H
