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

// TODO: Add an event manager that will handle the creation of event chains.
// These chains could be loaded from config, but will use event types to
// construct a series of events. So the generator would say 'give me marriages',
// the narrator for the era would do what needs doing. The event manager will
// just accept a given event type, maybe some additional params, and then return
// the next action. The narrator will have to parse that return

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
