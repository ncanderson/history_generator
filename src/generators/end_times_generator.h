#include <defs/history_generator_defs.h>
#include <generators/generator_base.h>

#ifndef END_TIMES_GENERATOR_H
#define END_TIMES_GENERATOR_H

namespace his_gen
{
/**
 * @brief Generate end times
 * @details Either the apocalypse of the setting, or an arbitrary
 * stopping point defined elsewhere.
 */
class End_times_generator : Generator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   */
  End_times_generator();

  /**
   * @brief Destructor.
   */
  virtual ~End_times_generator(){}

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

}; // class End_times_generator
}  // namespace his_gen

#endif // END_TIMES_GENERATOR_H
