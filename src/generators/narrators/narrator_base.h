/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef NARRATOR_BASE_H
#define NARRATOR_BASE_H

// Standard libs

// Application files
#include <models/entities/entity_base.h>
#include <models/events/event_base.h>
#include <data_access/data_access_manager.h>

namespace his_gen
{
// TODO: Single base class, specific impl for each generator

// TODO: Add an event manager that will handle the creation of event chains.
// These chains could be loaded from config, but will use event types to
// construct a series of events. So the generator would say 'give me marriages',
// the narrator for the era would do what needs doing. The event manager will
// just accept a given event type, maybe some additional params, and then return
// the next action. The narrator will have to parse that return

/**
 * @brief Base class for the generator narrators
 * @details The narrator handles calls from each generator. A generator might
 * say - 'give me marriages' and call one of these functions. The narrator would
 * then iterate through all entities and check for attraction. This base class
 * will contain some general functionality with implementation, and inheriting
 * classes will override and add new features as necessary.
 */
class Narrator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   * @brief data_definitions The data definitions
   */
  Narrator_base(const std::shared_ptr<his_gen::Data_definitions> data_definitions)
    :
    m_data_definitions(data_definitions)
  { }

  /**
   * @brief Destructor
   */
  virtual ~Narrator_base() = default;

  /**
   * @brief Inheriting classes must implement this function to create new entities.
   * @param entities The vector of entity pointers to populate.
   * @param entities_per_tick Configued entities to create per generator tick.
   */
  virtual void Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities) = 0;

  /**
   * @brief Inheriting classes must implement this function to create new events.
   * @param entities The vector of entity pointers to reference when creating events
   * @param events The vector of events to populate
   * @current_tick The current generation tick
   */
  virtual void Create_events(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                             std::vector<std::shared_ptr<his_gen::Event_base>>& events,
                             int64_t current_tick) =0;

protected:
  // Attributes
  /**
   * @brief Pointer to the data definitions
   */
  const std::shared_ptr<his_gen::Data_definitions> m_data_definitions;

  // Implementation
  /**
   * @brief Entity creation. Implementing classes must use their own
   * configuration for the purposes of entity creation.
   * @param entity_type The type of entity to create
   */
  virtual std::shared_ptr<his_gen::Entity_base> create_entity(his_gen::EEntity_type entity_type) = 0;

private:
  // Attributes

  // Implementation

}; // class Narrator_base
}  // namespace his_gen

#endif // NARRATOR_BASE_H
