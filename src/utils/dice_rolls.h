/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef DICE_ROLLS_H
#define DICE_ROLLS_H

#include <stdint.h>

namespace his_gen
{
/**
 * @brief Generate a random number between min and max
 * @param max_value
 * @param min_value
 * @return
 */
uint32_t Make_a_roll(uint32_t max_value, uint32_t min_value = 1);

/**
 * @brief Little wrapper to make it clear when we want a boolean value
 * @return Returns a boolean derived from a 0 - 1 range random roll.
 */
bool Flip_a_coin();

} // namespace his_gen

#endif // DICE_ROLLS_H
