/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORY_GENERATOR_H
#define HISTORY_GENERATOR_H

// Standard libraries

// Application files
#include <defs/history_generator_defs.h>
#include <generators/generator_base.h>

// Models
#include <models/generated_history.h>

namespace his_gen
{
/**
 * @brief Generate history
 * @details The history of mortals after the reign of the gods is over
 */
class Historical_era_generator : public Generator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   * @param his_gen_config Pointer to the application configuration
   */
  Historical_era_generator(const his_gen::History_generator_root_config& his_gen_config,
                           his_gen::Generated_history& generated_history,
                           const his_gen::Data_access_manager& data_access_manager);

  /**
   * @brief Destructor
   */
  ~Historical_era_generator(){}

  /**
   * @brief Run the generator
   */
  void Run() override;

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class History_generator
}  // namespace his_gen

#endif // HISTORY_GENERATOR_H
