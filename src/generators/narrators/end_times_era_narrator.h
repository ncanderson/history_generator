/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef END_TIMES_ERA_NARRATOR_H
#define END_TIMES_ERA_NARRATOR_H

// Standard libs

// Application files
#include <generators/narrators/narrator_base.h>
#include <utils/history_generator_root_config.h>
#include <models/events/event_base.h>

namespace his_gen
{
/**
 * @brief End times era generator narrator
 */
class End_times_era_narrator : public Narrator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  End_times_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                         const his_gen::History_generator_root_config& his_gen_config,
                         const std::shared_ptr<his_gen::Data_definitions> data_definitions);

  /**
   * @brief Destructor
   */
  ~End_times_era_narrator(){}

  /**
   * @brief Create_entities
   * @param entities
   * @param entities_per_tick
   */
  void Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                       const uint64_t current_tick) override;

  /**
   * @brief Create_events
   * @param entities The vector of entity pointers to reference when creating events
   * @param events The vector of events to populate
   * @param current_tick The current generation tick
   */
  void Create_events(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                     std::vector<std::shared_ptr<his_gen::Event_base>>& events,
                     const uint64_t current_tick) override;

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class End_times_era_narrator
}  // namespace his_gen

#endif // END_TIMES_ERA_NARRATOR_H
