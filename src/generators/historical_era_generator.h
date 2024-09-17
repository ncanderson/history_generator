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
  Historical_era_generator(std::shared_ptr<his_gen::History_generator_root_config> his_gen_config,
                           std::shared_ptr<his_gen::Generated_history> generated_history,
                           std::unique_ptr<const his_gen::Data_access_manager>& data_access_manager);

  /**
   * @brief Destructor.
   */
  virtual ~Historical_era_generator(){}

  /**
   * @brief Run the generator
   */
  void Run();

protected:
  // Attributes

  // Implementation
  /**
   * @brief Create a new entity
   */
  his_gen::Entity create_entity();

private:
  // Attributes
  /**
   * @brief Pointer to the generated history object
   */
  std::shared_ptr<his_gen::Generated_history> m_generated_history;

  // Implementation

}; // class History_generator
}  // namespace his_gen

#endif // HISTORY_GENERATOR_H
