/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef BOUNDS_H
#define BOUNDS_H

// Standard libs

// Application files

namespace his_gen
{
/**
 * @brief Helper utility to provide more visibility on 'magic'
 * min/max values
 */
class Bounds
{
public:
  // Constructor takes min and max by reference
  /**
   * @brief Constructor
   * @param min_val Min value for this object
   * @param max_val Max value for this object
   */
  Bounds(const double min_val,
         const double max_val);

  /**
   * @brief Enforce method clamps the given values to the stored bounds
   * @param value_in The value to check - if bounds are exceeded they
   * will be clamped to the specified min and max
   */
  void Enforce(double& value_in) const;

private:
  /**
   * @brief m_min The min value
   */
  const double m_min;

  /**
   * @brief m_max The max value
   */
  const double m_max;

};
}

#endif
