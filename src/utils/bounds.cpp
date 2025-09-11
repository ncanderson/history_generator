/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <utils/bounds.h>

///////////////////////////////////////////////////////////////////////

his_gen::Bounds::Bounds(const double min_val,
                        const double max_val)
  :
  m_min(min_val),
  m_max(max_val)
{ }

///////////////////////////////////////////////////////////////////////

void his_gen::Bounds::Enforce(double& value_in) const
{
  // Enforce min
  if(value_in < m_min)
  {
    value_in = m_min;
  }
  // Enforce max
  else if(value_in > m_max)
  {
    value_in = m_max;
  }
}

///////////////////////////////////////////////////////////////////////
