/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/generated_history.h>

///////////////////////////////////////////////////////////////////////

void his_gen::Generated_history::To_json(nlohmann::json& json,
                                        std::shared_ptr<his_gen::Generated_history> generated_history)
{
  json = nlohmann::json
  {
    {"entity_relationships", Entity_relationships},
    {"entity_type_relationship_types", Entity_type_relationship_types},
    {"entity_types", Entity_types},
    {"entities", Entities},
    {"relationship_types", Relationship_types}
  };
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
