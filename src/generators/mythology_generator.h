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
class Mythology_generator : public Generator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   */
  Mythology_generator();

  /**
   * @brief Destructor.
   */
  virtual ~Mythology_generator(){}

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
