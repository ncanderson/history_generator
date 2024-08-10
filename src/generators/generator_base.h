/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef GENERATOR_BASE_H
#define GENERATOR_BASE_H

#include <defs/history_generator_defs.h>
#include <utils/history_generator_root_config.h>

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
   * @brief Constructor
   * @param generation_complete Default
   * @param current_stage
   */
  Generator_base(bool generation_complete,
                 his_gen::Stage current_stage,
                 his_gen::History_generator_root_config &his_gen_config)
      :
      m_generation_complete(generation_complete),
      m_current_stage(current_stage),
      m_his_gen_config(his_gen_config)
  {

  }

  /**
   * @brief Run the generator
   */
  virtual void Run() = 0;

  /**
   * @brief Return boolean indicating completion status of this generator
   * @return True if generation is complete, false otherwise.
   */
  bool Get_generation_complete()
  {
    return m_generation_complete;
  }

  /**
   * @brief Set generation status for this generator
   * @param generation_complete True if generation is complete, false otherwise.
   */
  void Set_generation_complete(bool generation_complete)
  {
    m_generation_complete = generation_complete;
  }

protected:
  // Attributes
  /**
   * @brief m_generation_complete Completion status of the current generator
   */
  bool m_generation_complete;

  /**
   * @brief m_current_stage Current stage for this generator
   */
  his_gen::Stage m_current_stage;

  /**
   * @brief m_his_gen_config Application configuration
   */
  his_gen::History_generator_root_config &m_his_gen_config;

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Generator_base
}  // namespace his_gen

#endif // GENERATOR_BASE_H
