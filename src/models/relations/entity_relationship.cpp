/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/relations/entity_relationship.h>

///////////////////////////////////////////////////////////////////////

his_gen::Entity_relationship::Entity_relationship(boost::uuids::uuid relationship_id,
                                                  std::shared_ptr<his_gen::Entity_base> entity_1,
                                                  std::shared_ptr<his_gen::Entity_base> entity_2)
  :
  m_relationship_id(relationship_id),
  m_entity_1(entity_1),
  m_entity_2(entity_2)
{

}


///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_relationship& entity_relationship)
{
  json = nlohmann::json
  {
    // like this:
    // {"json key", object attr}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_relationship& entity_relationship)
{
  // do it like this
  // json.at("name").get_to(entity.Name);
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
