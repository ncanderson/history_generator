/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Application files
#include <utils/dice_rolls.h>

///////////////////////////////////////////////////////////////////////

bool his_gen::dice::Flip_a_coin()
{
  return static_cast<bool>(Make_a_roll<int8_t>(1, 0));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
