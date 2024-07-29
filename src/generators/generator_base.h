#include <defs/history_generator_defs.h>

#ifndef GENERATOR_BASE_H
#define GENERATOR_BASE_H

namespace his_gen
{
/**
 * @brief Abstract base class for the other generators
 */
class Generator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Run the generator
   */
  virtual void Run() = 0;

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  his_gen::Stage m_current_stage;

  // Implementation

}; // class Generator_base
}  // namespace his_gen

#endif // GENERATOR_BASE_H
