/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef MYTH_ERA_NARRATOR_H
#define MYTH_ERA_NARRATOR_H

// Standard libs

// Application files
#include <utils/history_generator_root_config.h>
#include <generators/narrators/narrator_base.h>
#include <models/entities/entity_base.h>
#include <models/events/event_base.h>

// Modules
#include <modules/names.h>

namespace his_gen
{
/**
 * @brief Myth era generator narrator
 */
class Mythological_era_narrator : public Narrator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Mythological_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                            const his_gen::History_generator_root_config& his_gen_config);

  /**
   * @brief Destructor
   */
  ~Mythological_era_narrator(){}

  /**
   * @brief Create_entities
   * @param entities
   * @param current_tick
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
  void Manage_events(his_gen::Generated_history& history_of_the_world,
                     const uint64_t current_tick) override;

  /**
   * @brief The first being in this mythology
   */
  void Create_progenitor_deity(his_gen::Entities& entities);

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Config for this generation era
   */
  History_generator_root_config m_config;

  // Implementation

}; // class Myth_era_narrator
}  // namespace his_gen

#endif // MYTH_ERA_NARRATOR_H
