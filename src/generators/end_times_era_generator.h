/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef END_TIMES_GENERATOR_H
#define END_TIMES_GENERATOR_H

// Standard libraries

// Application files
#include <defs/history_generator_defs.h>
#include <generators/generator_base.h>

// Models
#include <models/generated_history.h>

namespace his_gen
{
/**
 * @brief Generate end times
 * @details Either the apocalypse of the setting, or an arbitrary
 * stopping point defined elsewhere.
 */
class End_times_era_generator : public Generator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   * @param his_gen_config Pointer to the application configuration
   * @param generated_history Pointer to the generated history object
   */
  End_times_era_generator(his_gen::History_generator_root_config &his_gen_config,
                          models::Generated_history &generated_history);

  /**
   * @brief Destructor.
   */
  virtual ~End_times_era_generator(){}

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
  models::Entity create_entity();

private:
  // Attributes
  /**
   * @brief Pointer to the generated history object
   */
  models::Generated_history &m_generated_history;

  // Implementation

}; // class End_times_generator
}  // namespace his_gen

#endif // END_TIMES_GENERATOR_H
