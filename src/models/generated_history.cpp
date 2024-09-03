/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/generated_history.h>

///////////////////////////////////////////////////////////////////////

void models::Generated_history::To_json(nlohmann::json& json,
                                        std::shared_ptr<models::Generated_history> generated_history)
{
  json = nlohmann::json
  {
    {"generated_history", generated_history->Entities.size() }
  };
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
