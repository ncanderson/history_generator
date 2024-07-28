#ifndef HISTORY_GENERATOR_DEFS_H
#define HISTORY_GENERATOR_DEFS_H

namespace his_gen
{

/**
 * @brief The Era enum
 * @details Track the current position within the overall generation
 */
enum Era
{
  ERA_Mythology,  ///< Age of mythology, especially gods
  ERA_History,    ///< Age of history, mostly humans
  ERA_Terminate   ///< Any wrap-up or post-generation tasks
};

/**
 * @brief The Stage enum
 * @details Track steps taken within each generation era
 */
enum Stage
{
  STAGE_Init,      ///< Initialize and setup
  STAGE_Run,       ///< Execution of era generation
  STAGE_Terminate  ///< Wrap-up and transition
};

}  // namespace his_gen

#endif // HISTORY_GENERATOR_DEFS_H
