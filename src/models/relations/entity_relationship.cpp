/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/relations/entity_relationship.h>

///////////////////////////////////////////////////////////////////////

using er = his_gen::Entity_relationship;

///////////////////////////////////////////////////////////////////////

er::Entity_relationship(const boost::uuids::uuid& relationship_id,
                        const his_gen::Relationship_type& relationship_type,
                        const std::shared_ptr<his_gen::Entity_base>& entity_1,
                        const std::shared_ptr<his_gen::Entity_base>& entity_2)
  :
  m_entity_relationship_id(relationship_id),
  m_relationship_type(relationship_type),
  m_entity_1(entity_1),
  m_entity_2(entity_2)
{ }

///////////////////////////////////////////////////////////////////////

er::Entity_relationship_ptr er::Entity_relationship_factory(std::shared_ptr<his_gen::Entity_base>& entity_1,
                                                            std::shared_ptr<his_gen::Entity_base>& entity_2,
                                                            const his_gen::ERelationship_type& relationship_type)
{
  // Ent/Rel ID, for storage in the generated history map
  boost::uuids::uuid entity_relationship_id = boost::uuids::random_generator()();

  // Both entities need that ID in their own relationship map
  entity_1->Add_relationship_id(entity_relationship_id);
  entity_2->Add_relationship_id(entity_relationship_id);

  // Create the relationship
  his_gen::Relationship_type rel_instance = his_gen::Relationship_type(relationship_type);

  // Return the full entity relationship
  return std::make_shared<his_gen::Entity_relationship>(entity_relationship_id,
                                                        rel_instance,
                                                        entity_1,
                                                        entity_2);
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_relationship& entity_relationship)
{
  json = nlohmann::json
  {
    {"entity_relationship_id", entity_relationship.Get_entity_relationship_id()},
    {"relationship_type", entity_relationship.Get_relationship_type().Get_name()},
    {"entity_1_id", entity_relationship.Get_entity_1()->Get_entity_id()},
    {"entity_2_id", entity_relationship.Get_entity_2()->Get_entity_id()},
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_relationship& entity_relationship)
{
  // Need to deserialize the values in `json`, then call the factory to ensure full instantiation
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
