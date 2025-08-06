/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/physicality_attraction.h>

///////////////////////////////////////////////////////////////////////

his_gen::Physicality_attraction::Physicality_attraction()
{

}

///////////////////////////////////////////////////////////////////////

int8_t his_gen::Physicality_attraction::derive_attraction_flexibility(std::map<his_gen::Attribute, int8_t> attributes)
{
  return 0;
}

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Physicality_attraction& physicality_attraction)
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Physicality_attraction& physicality_attraction)
{

}

///////////////////////////////////////////////////////////////////////
