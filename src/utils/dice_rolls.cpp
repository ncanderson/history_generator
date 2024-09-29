/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs
#include <random>

// Application files
#include <utils/dice_rolls.h>

///////////////////////////////////////////////////////////////////////

uint32_t his_gen::Make_a_roll(uint32_t max_value,
                              uint32_t min_value)
{
  // Initialize a random number generator
  std::random_device rand;
  std::mt19937 generate(rand());
  std::uniform_int_distribution<> distrib(min_value, max_value);

  return distrib(generate);
}

///////////////////////////////////////////////////////////////////////

bool his_gen::Flip_a_coin()
{
  return static_cast<bool>(Make_a_roll(1, 0));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
