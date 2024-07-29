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
class History_generator : Generator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   */
  History_generator();

  /**
   * @brief Destructor.
   */
  virtual ~History_generator(){}

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
