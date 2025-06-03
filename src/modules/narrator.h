/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef NARRATOR_H
#define NARRATOR_H

// Standard libs

// Application files

namespace his_gen
{
// TODO: Should each generator have its own narrator or will a single narrator
// work for all generators?
/**
 * @brief Narrator module
 * @details The narrator handles calls from each generator. A generator might
 * say - 'give me marriages' and call one of these functions. The narrator would
 * then iterate through all entities and check for attraction.
 */
class Narrator
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Narrator();

  /**
   * @brief Destructor
   */
  ~Narrator(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Narrator
}  // namespace his_gen

#endif // NARRATOR_H
