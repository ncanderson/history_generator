/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef EVENT_VISITOR_H
#define EVENT_VISITOR_H

// Standard libs

// JSON

// Application files
#include <utils/history_generator_utils.h>
#include <models/entities/entity_base.h>

namespace his_gen
{

/////////////////////////////////////////////////
// Forward declarations of implementing classes

class Entity_sentient;
class Entity_deity;

/**
 * @brief Implementation of the visitor pattern, which will allow
 * events that require specific entity types to retrieve those methods
 * at runtime.
 * @details This class should contain a pure virtual method for any derived
 * entity type that will require specific handling in an event. Those entities
 * should then include an override of Visit(). Additionally, each derived entity
 * then needs an implementation of Acccept(), which will call the correct
 * visitor function using itself as an argument. Finally, within each event,
 * Override and implement Visit() to handle the specific needs of that
 * entity type.
 */
class Event_visitor
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Destructor
   */
  virtual ~Event_visitor() = default;

  /**
   * Any entities that will require specific handling for specific events
   * should be declared here. By providing a default implementation that just
   * raises an error, the need for every event to implement a Visit_entity() function
   * for every derived entity that exists is eliminated. The error means
   * that if a Visit_entity() function is missing an implementation but is called,
   * we're on the highway to the danger zone and an error will be raised.
   */
  virtual void Visit_entity(Entity_sentient& e) {}
  virtual void Visit_entity(Entity_deity& e) {}

};
}

#endif
