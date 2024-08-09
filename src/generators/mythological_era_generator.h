#include <defs/history_generator_defs.h>
#include <generators/generator_base.h>

#ifndef MYTHOLOGY_GENERATOR_H
#define MYTHOLOGY_GENERATOR_H

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
   */
  Mythological_era_generator(his_gen::History_generator_root_config &his_gen_config);

  /**
   * @brief Destructor.
   */
  virtual ~Mythological_era_generator(){}

  /**
   * @brief Run the generator
   */
  void Run();

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Mytholog_generator
}  // namespace his_gen

#endif // MYTHOLOGY_GENERATOR_H
