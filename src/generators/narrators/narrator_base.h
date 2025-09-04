/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef NARRATOR_BASE_H
#define NARRATOR_BASE_H

// Standard libs
#include <unordered_set>
#include <boost/functional/hash.hpp>

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
    m_event_scheduler(),
    m_entity_ids(),
    m_event_ids()
  { }

  /**
   * @brief Destructor
   */
  virtual ~Narrator_base() = default;

  /**
   * @brief Inheriting classes must implement this function to create new entities.
   * @param entities The vector of entity pointers to populate.
   * @current_tick The current generation tick
   */
  virtual void Create_entities(his_gen::Entities& entities,
                               const uint64_t current_tick) = 0;

  /**
   * @brief Inheriting classes must implement this function to create new events
   * and manage scheduled events.
   * @param entities The vector of entity pointers to reference when creating events
   * @param events The vector of events to populate
   * @param entity_relationships The vector of entity relationships to populate
   * @current_tick The current generation tick
   */
  virtual void Manage_events(his_gen::Entities& entities,
                             his_gen::Events& events,
                             his_gen::Entity_relationships& entity_relationships,
                             const uint64_t current_tick) =0;

  /**
   * @brief This class maintains a list of all entity and event IDs that are currently
   * interesting, allowing those IDs to be used for random selection
   * @param entities All entities, from which IDs will be extracted
   * @param events All events, from which IDs will be extracted
   */
  void Refresh_generation_id_lists(const his_gen::Entities& entities,
                                   const his_gen::Events& events)
  {
    // Entities
    // Copy existing IDs into an unordered set to ensure duplicates are not inserted
    std::unordered_set<boost::uuids::uuid,
                       boost::hash<boost::uuids::uuid>> ents(m_entity_ids.begin(),
                                                             m_entity_ids.end());

    for(const auto& [id, _] : entities)
    {
      // Attempt to insert the ID, 'insert()' returns true if id was not
      // already present, in that case insert to m_entity_ids
      if(ents.insert(id).second)
      {
        m_entity_ids.push_back(id);
      }
    }

    // Entities
    // Copy existing IDs into an unordered set to ensure duplicates are not inserted
    std::unordered_set<boost::uuids::uuid,
                       boost::hash<boost::uuids::uuid>> evts(m_event_ids.begin(),
                                                             m_event_ids.end());

    for(const auto& [id, _] : events)
    {
      // Attempt to insert the ID, 'insert()' returns true if id was not
      // already present, in that case insert to m_event_ids
      if(evts.insert(id).second)
      {
        m_event_ids.push_back(id);
      }
    }
  }

protected:
  // Attributes
  /**
   * @brief Event scheduler for letting events determine the next step
   */
  Event_scheduler m_event_scheduler;

  /**
   * @brief All entity IDs currently under management by this narrator
   */
  std::vector<boost::uuids::uuid> m_entity_ids;

  /**
   * @brief All event IDs currently under management by this narrator
   */
  std::vector<boost::uuids::uuid> m_event_ids;

  // Implementation
  /**
   * @brief Run events that have been scheduled by other events
   * @param entities
   * @param entity_relationships
   * @param current_tick
   */
  void run_scheduled_events(his_gen::Entities& entities,
                            his_gen::Entity_relationships entity_relationships,
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
