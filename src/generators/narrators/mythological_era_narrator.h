/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef MYTH_ERA_NARRATOR_H
#define MYTH_ERA_NARRATOR_H

// Standard libs

// Application files
#include <utils/history_generator_root_config.h>
#include <generators/narrators/narrator_base.h>
#include <models/entity_base.h>

// Modules
#include <modules/names.h>

namespace his_gen
{
/**
 * @brief Myth era generator narrator
 */
class Myth_era_narrator : public Narrator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Myth_era_narrator(const his_gen::Data_access_manager& data_access_manager,
                    const his_gen::History_generator_root_config& his_gen_config);

  /**
   * @brief Destructor
   */
  ~Myth_era_narrator();

  /**
   * @brief Create_entities
   * @param entities
   * @param entities_per_tick
   */
  void Create_entities(std::vector<std::shared_ptr<his_gen::Entity_base>>& entities,
                       int64_t entities_per_tick) override;

  /**
   * @brief The first being in this mythology
   */
  void Create_progenitor_deity(std::vector<std::shared_ptr<his_gen::Entity_base>>& Entities);

protected:
  // Attributes

  // Implementation
  /**
   * @brief Create a new entity
   */
  std::shared_ptr<his_gen::Entity_base> create_entity() override;

private:
  // Attributes
  /**
   * @brief Config for this generation era
   */
  History_generator_root_config m_config;

  // TODO: there should be a better place for this, otherwise we'll get tons
  // of duplicate names if each generator has its own copy
  /**
   * @brief Names object
   */
  Names m_names;

  // Implementation

}; // class Myth_era_narrator
}  // namespace his_gen

#endif // MYTH_ERA_NARRATOR_H
