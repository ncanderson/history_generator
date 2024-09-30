/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entity_sentient.h>

// Defs and Utils
#include <defs/json_helper_defs.h>
#include <utils/dice_rolls.h>

///////////////////////////////////////////////////////////////////////

his_gen::Entity_sentient::Entity_sentient(std::string name,
                                          std::string title,
                                          bool full_random_reproduction)
    :
    Entity_base(name, title),
    m_personality(),
    m_personality_attraction(),
    m_can_sire_young(),
    m_can_bear_young()
{
  // Register the derived class with the JSON serializer
  Polymorphic_serializer<his_gen::Entity_base>::register_types<his_gen::Entity_base,
                                                               his_gen::Entity_sentient>();

  // Initialize reproductive ability
  if(full_random_reproduction)
  {
    m_can_sire_young = his_gen::Flip_a_coin();
    m_can_bear_young = his_gen::Flip_a_coin();
  }
  else
  {
    // TODO: This doesn't account for infertility when non-randomizing
    // reproduction ability
    m_can_sire_young = his_gen::Flip_a_coin();
    m_can_bear_young = !m_can_sire_young;
  }
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_sentient& entity_sentient)
{
  nlohmann::to_json(json, static_cast<Entity_base>(entity_sentient));
  json.update(
  {
    {"personality", entity_sentient.Get_personality()},
    {"can_sire_young", entity_sentient.Get_can_sire()},
    {"can_bear_young", entity_sentient.Get_can_bear()}
  });
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_sentient& entity_sentient)
{
  entity_sentient.Set_name(json.at("name"));
  entity_sentient.Set_title(json.at("title"));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
