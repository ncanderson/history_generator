/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/data_definitions.h>

///////////////////////////////////////////////////////////////////////

his_gen::Data_definitions::Data_definitions()
    :
    Entity_type_relationship_types(),
    Entity_types(),
    Relationship_types()
{

}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Data_definitions& data_definitions)
{
  json = nlohmann::json
  {
    {"entity_type_relationship_types", data_definitions.Entity_type_relationship_types},
    {"entity_types", data_definitions.Entity_types},
    {"relationship_type", data_definitions.Relationship_types}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Data_definitions& data_definitions)
{
  json.at("entity_type_relationship_types").get_to(data_definitions.Entity_type_relationship_types);
  json.at("entity_types").get_to(data_definitions.Entity_types);
  json.at("relationship_type").get_to(data_definitions.Relationship_types);
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
