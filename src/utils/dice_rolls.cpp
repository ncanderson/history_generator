/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Application files
#include <utils/dice_rolls.h>

///////////////////////////////////////////////////////////////////////

std::mt19937& his_gen::dice::Get_generator()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  return gen;
}

///////////////////////////////////////////////////////////////////////

bool his_gen::dice::Flip_a_coin()
{
  return static_cast<bool>(Make_a_roll<int8_t>(1, 0));
}

///////////////////////////////////////////////////////////////////////
