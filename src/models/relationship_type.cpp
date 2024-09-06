/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/relationship_type.h>

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Relationship_type& relationship_type)
{
  json = nlohmann::json
  {

  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Relationship_type& relationship_type)
{
  // do it like this
  // json.at("name").get_to(entity.Name);
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
