/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/personality.h>

// Application files
#include <utils/dice_rolls.h>

///////////////////////////////////////////////////////////////////////

his_gen::Personality::Personality()
{
  m_personality_attributes[ATTRIBUTE_Aggressive_passive] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Ambitious_lazy] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Avoidant_sociable] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Brave_cowardly] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Cooperative_difficult] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Cruel_kind] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Decisive_indecisive] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Diligent_lazy] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Flexible_extremist] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Frank_evasive] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Generous_selfish] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Helpful_useless] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Jealous_compassionate] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Placid_excitable] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Thoughtful_rash] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Thrifty_extravagant] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Truculent_amiable] = his_gen::Make_a_roll(100);
  m_personality_attributes[ATTRIBUTE_Witty_humorless] = his_gen::Make_a_roll(100);
};

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json, const his_gen::Personality& personality)
{
  nlohmann::json attributes_converted;
  std::map<Attribute, int8_t> attributes = personality.Get_attributes();
  for(auto it = attributes.begin(); it != attributes.end(); ++it)
  {
    attributes_converted[his_gen::Get_attribute_string(it->first)] = it->second;
  }

  json = nlohmann::json
  {
    {"personality_attributes", attributes_converted}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json, his_gen::Personality& personality)
{

}

///////////////////////////////////////////////////////////////////////
// END OF FILE
