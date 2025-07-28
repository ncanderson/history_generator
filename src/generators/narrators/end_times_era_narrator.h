/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef END_TIMES_ERA_NARRATOR_H
#define END_TIMES_ERA_NARRATOR_H

// Standard libs

// Application files
#include <generators/narrators/narrator_base.h>
#include <utils/history_generator_root_config.h>

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
                       int64_t entities_per_tick) override;

  /**
   * @brief Handle_events
   * @param entities
   */
  void Handle_events(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities) override;

protected:
  // Attributes

  // Implementation
  /**
   * @brief Create a new entity
   */
  std::shared_ptr<his_gen::Entity_base> create_entity() override;

private:
  // Attributes

  // Implementation

}; // class End_times_era_narrator
}  // namespace his_gen

#endif // END_TIMES_ERA_NARRATOR_H
