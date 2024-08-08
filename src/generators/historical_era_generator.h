#include <defs/history_generator_defs.h>
#include <generators/generator_base.h>

#ifndef HISTORY_GENERATOR_H
#define HISTORY_GENERATOR_H

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
   */
  Historical_era_generator();

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

private:
  // Attributes
  his_gen::Stage m_current_stage;

  // Implementation

}; // class History_generator
}  // namespace his_gen

#endif // HISTORY_GENERATOR_H
