/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORICAL_ERA_NARRATOR_H
#define HISTORICAL_ERA_NARRATOR_H

// Standard libs

// Application files
#include <generators/narrators/narrator_base.h>
#include <utils/history_generator_root_config.h>
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @brief Historical era generator narrator
 */
class Historical_era_narrator : public Narrator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Historical_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                          const his_gen::History_generator_root_config& his_gen_config);

  /**
   * @brief Destructor
   */
  ~Historical_era_narrator(){}

  /**
   * @brief Create_entities
   * @param entities
   * @param entities_per_tick
   */
  void Create_entities(his_gen::Entities& entities,
                       const uint64_t current_tick) override;

  /**
   * @brief Create new events and run scheduled events
   * @param entities The vector of entity pointers to reference when creating events
   * @param events The vector of events to populate
   * @param entity_relationships The vector of entity relationships to populate
   * @param current_tick The current generation tick
   */
  void Manage_events(his_gen::Entities& entities,
                     his_gen::Events& events,
                     his_gen::Entity_relationships& entity_relationships,
                     const uint64_t current_tick) override;

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Historical_era_narrator
}  // namespace his_gen

#endif // HISTORICAL_ERA_NARRATOR_H
