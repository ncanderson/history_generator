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
#include <utils/event_scheduler.h>

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
   */
  Narrator_base()
    :
    m_event_scheduler()
  { }

  /**
   * @brief Destructor
   */
  virtual ~Narrator_base() = default;

  /**
   * Usings
   */
  using Entities = std::vector<std::shared_ptr<his_gen::Entity_base>>;
  using Events = std::vector<std::shared_ptr<his_gen::Event_base>>;
  using Entity_relationships = std::map<boost::uuids::uuid, std::shared_ptr<his_gen::Entity_relationship>>;

  /**
   * @brief Inheriting classes must implement this function to create new entities.
   * @param entities The vector of entity pointers to populate.
   * @current_tick The current generation tick
   */
  virtual void Create_entities(Entities& entities,
                               const uint64_t current_tick) = 0;

  /**
   * @brief Inheriting classes must implement this function to create new events
   * and manage scheduled events.
   * @param entities The vector of entity pointers to reference when creating events
   * @param events The vector of events to populate
   * @param entity_relationships The vector of entity relationships to populate
   * @current_tick The current generation tick
   */
  virtual void Manage_events(Entities& entities,
                             Events& events,
                             Entity_relationships& entity_relationships,
                             const uint64_t current_tick) =0;

protected:
  // Attributes
  /**
   * @brief Event scheduler for letting events determine the next step
   */
  Event_scheduler m_event_scheduler;

  // Implementation
  void run_scheduled_events(Event_base::Entities& entities,
                            Event_base::Entity_relationships entity_relationships,
                            const uint64_t current_tick)
  {
    // Temp instance of scheduler, so we can avoid an infinte loop if using the
    // class member to schedule
    Event_scheduler temp_scheduler = Event_scheduler();

    while(m_event_scheduler.More_events_to_run(current_tick))
    {
      m_event_scheduler.Prepare_next_event(current_tick)->Run(entities,
                                                              entity_relationships,
                                                              temp_scheduler);
    }

    // Merge any new events that were scheduled following scheduled events
    // into the main event schedule
    m_event_scheduler.Merge_scheduled_events(temp_scheduler);
  }

private:
  // Attributes

  // Implementation

}; // class Narrator_base
}  // namespace his_gen

#endif // NARRATOR_BASE_H
