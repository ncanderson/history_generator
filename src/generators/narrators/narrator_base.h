/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef NARRATOR_BASE_H
#define NARRATOR_BASE_H

// Standard libs

// Application files
#include <models/entities/entity_base.h>
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
   */
  Narrator_base(const std::shared_ptr<his_gen::Data_definitions> data_definitions);

  /**
   * @brief Destructor
   */
  ~Narrator_base() = default;

  /**
   * @brief Inheriting classes must implement this function to create new entities.
   * @param entities The vector of entity pointers to populate.
   * @param entities_per_tick Configued entities to create per generator tick.
   */
  virtual void Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                               int64_t entities_per_tick) = 0;

  /**
   * @brief Check all entities in `entities` for attraction
   * @param entities Vector of entities to review
   * @param enitity_relationships Map to track any new relationships
   */
  void Run_entity_attraction(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                             std::map<boost::uuids::uuid, std::shared_ptr<his_gen::Entity_relationship>>& enitity_relationships);

protected:
  // Attributes

  // Implementation
  /**
   * @brief Entity creation. Implementing classes must use their own
   * configuration for the purposes of entity creation.
   */
  virtual std::shared_ptr<his_gen::Entity_base> create_entity() = 0;

private:
  // Attributes
  /**
   * @brief Pointer to the data definitions
   */
  const std::shared_ptr<his_gen::Data_definitions> m_data_definitions;

  // Implementation

}; // class Narrator_base
}  // namespace his_gen

#endif // NARRATOR_BASE_H
