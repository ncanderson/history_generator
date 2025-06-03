/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef NARRATOR_BASE_H
#define NARRATOR_BASE_H

// Standard libs

// Application files

namespace his_gen
{
// TODO: Single base class, specific impl for each generator

// TODO: Add an event manager that will handle the creation of event chains.
// These chains could be loaded from config, but will use event types to
// construct a series of events. So the generator would say 'give me marriages',
// the narrator for the era would do what needs doing. The event manager will
// just accept a given event type, maybe some additional params, and then return
// the next action. The narrator will have to parse that return

/**
 * @brief Base class for the generator narrators
 * @details The narrator handles calls from each generator. A generator might
 * say - 'give me marriages' and call one of these functions. The narrator would
 * then iterate through all entities and check for attraction. This base class
 * will contain some general functionality with implementation, and inheriting
 * classes will override and add new features as necessary.
 */
class Narrator_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Narrator_base();

  /**
   * @brief Destructor
   */
  ~Narrator_base();

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Narrator_base
}  // namespace his_gen

#endif // NARRATOR_BASE_H
