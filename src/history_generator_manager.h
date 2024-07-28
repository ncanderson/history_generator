#include <defs/history_generator_defs.h>

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
   * @brief Destructor.
   */
  virtual ~History_generator_manager(){}

  /**
   * @brief Run the application state machine
   */
  his_gen::Era Run();

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  his_gen::Era m_current_era;

  // Implementation

}; // class History_generator_manager
}  // namespace his_gen

#endif // HISTORY_GENERATOR_MANAGER_H
