/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORICAL_ERA_NARRATOR_H
#define HISTORICAL_ERA_NARRATOR_H

// Standard libs

// Application files
#include <generators/narrators/narrator_base.h>

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
  Historical_era_narrator(const his_gen::Data_access_manager& data_access_manager);

  /**
   * @brief Destructor
   */
  ~Historical_era_narrator();

  /**
   * @brief Create_entities
   * @param entities
   * @param entities_per_tick
   */
  void Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                       int64_t entities_per_tick) override;

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

}; // class Historical_era_narrator
}  // namespace his_gen

#endif // HISTORICAL_ERA_NARRATOR_H
