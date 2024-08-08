// Standard libs
#include <memory>
// Application files
#include <generators/mythological_era_generator.h>
#include <generators/historical_era_generator.h>
#include <generators/end_times_era_generator.h>
#include <defs/history_generator_defs.h>
#include <utils/history_generator_config.h>

#ifndef HISTORY_GENERATOR_MANAGER_H
#define HISTORY_GENERATOR_MANAGER_H

namespace his_gen
{
/**
 * @brief Application manager
 * @details Manage the application state, allowing main() to delete
 * the Run function and tracking the overall place in generation.
 */
class History_generator_manager
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   */
  History_generator_manager();

  /**
   * @brief JSON constructor.
   */
  History_generator_manager(his_gen::History_generator_config &his_gen_config);

  /**
   * @brief Destructor.
   */
  virtual ~History_generator_manager(){}

  /**
   * @brief Run the application state machine
   * @details This function will loop until all generators have completed. Each
   * loop will trigger the Run() function for the current generator; those
   * generators will all maintain their generation state internally.
     */
  his_gen::Era Run();

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  /**
   * @brief m_his_gen_config Application configuration
   */
  his_gen::History_generator_config &m_his_gen_config;

  /**
   * @brief m_current_era Variable to track the generator's current era
   */
  his_gen::Era m_current_era;

  /**
   * @brief m_myth_gen Shared pointer to the Mythology generator
   */
  std::shared_ptr<his_gen::Mythological_era_generator> m_myth_gen;

  /**
   * @brief m_myth_gen Shared pointer to the History generator
   */
  std::shared_ptr<his_gen::Historical_era_generator> m_hist_gen;

  /**
   * @brief m_myth_gen Shared pointer to the End times generator
   */
  std::shared_ptr<his_gen::End_times_era_generator> m_end_times_gen;

  /**
   * @brief Number of iterations through this classes Run() function
   */
  uint32_t m_num_iterations;

  // Implementation

}; // class History_generator_manager
}  // namespace his_gen

#endif // HISTORY_GENERATOR_MANAGER_H
