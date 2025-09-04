/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORY_GENERATOR_ALIASES_H
#define HISTORY_GENERATOR_ALIASES_H

// Standard libs
#include <map>
#include <memory>
#include <boost/uuid/uuid.hpp>

// JSON

// Application files

namespace his_gen
{

/**
 * Usings, with forward declarations to prevent circular includes
 */
class Entity_base;
using Entities = std::map<boost::uuids::uuid, std::shared_ptr<his_gen::Entity_base>>;

class Event_base;
using Events = std::map<boost::uuids::uuid, std::shared_ptr<his_gen::Event_base>>;

class Entity_relationship;
using Entity_relationships = std::map<boost::uuids::uuid, std::shared_ptr<his_gen::Entity_relationship>>;

} // namespace his_gen

#endif // HISTORY_GENERATOR_ALIASES_H
