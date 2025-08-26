/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef MYTHOLOGY_GENERATOR_H
#define MYTHOLOGY_GENERATOR_H

// Standard libraries

// Application files
#include <defs/history_generator_defs.h>
#include <generators/generator_base.h>
#include <generators/narrators/mythological_era_narrator.h>

// Models
#include <models/generated_history.h>

namespace his_gen
{
/**
 * @brief Generate a mythology
 * @details Create gods, let them much around, and determine
 * how time gives way to the age of mortals
 */
class Mythological_era_generator : public Generator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   * @param his_gen_config Pointer to the application configuration
   */
  Mythological_era_generator(const his_gen::History_generator_root_config& his_gen_config,
                             his_gen::Generated_history& generated_history,
                             const his_gen::Data_access_manager& data_access_manager);

  /**
   * @brief Destructor
   */
  ~Mythological_era_generator(){}

  /**
   * @brief Run the generator
   */
  void Run() override;

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Narrator to handle specific events within the generator context
   */
  Mythological_era_narrator m_myth_narrator;

  // Implementation

}; // class Mytholog_generator
}  // namespace his_gen

#endif // MYTHOLOGY_GENERATOR_H
