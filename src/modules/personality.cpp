/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/personality.h>

// Application files
#include <utils/dice_rolls.h>

using personality = his_gen::Attribute_enums::EPersonality;

///////////////////////////////////////////////////////////////////////

his_gen::Personality::Personality()
  :
  Entity_attributes_base<Personality, his_gen::Attribute_enums::EPersonality>()
{ };

///////////////////////////////////////////////////////////////////////

his_gen::Personality::Personality_attribute_map his_gen::Personality::construct_attributes()
{
  Personality_attribute_map personality_attributes;

  int8_t aggressive_passive = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Aggressive] = aggressive_passive;
  personality_attributes[personality::EPERSONALITY_Passive] = his_gen::ATTRIBUTE_MAX - aggressive_passive;
  int8_t ambitious_content = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Ambitious] = ambitious_content;
  personality_attributes[personality::EPERSONALITY_Content] = his_gen::ATTRIBUTE_MAX - ambitious_content;
  int8_t avoidant_sociable = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Avoidant] = avoidant_sociable;
  personality_attributes[personality::EPERSONALITY_Sociable] = his_gen::ATTRIBUTE_MAX - avoidant_sociable;
  int8_t brave_cowardly = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Brave] = brave_cowardly;
  personality_attributes[personality::EPERSONALITY_Cowardly] = his_gen::ATTRIBUTE_MAX - brave_cowardly;
  int8_t cooperative_difficult = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Cooperative] = cooperative_difficult;
  personality_attributes[personality::EPERSONALITY_Difficult] = his_gen::ATTRIBUTE_MAX - cooperative_difficult;
  int8_t cruel_kind = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Cruel] = cruel_kind;
  personality_attributes[personality::EPERSONALITY_Kind] = his_gen::ATTRIBUTE_MAX - cruel_kind;
  int8_t decisive_indecisive = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Decisive] = decisive_indecisive;
  personality_attributes[personality::EPERSONALITY_Indecisive] = his_gen::ATTRIBUTE_MAX - decisive_indecisive;
  int8_t diligent_lazy = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Diligent] = diligent_lazy;
  personality_attributes[personality::EPERSONALITY_Lazy] = his_gen::ATTRIBUTE_MAX - diligent_lazy;
  int8_t flexible_extremist = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Flexible] = flexible_extremist;
  personality_attributes[personality::EPERSONALITY_Extremist] = his_gen::ATTRIBUTE_MAX - flexible_extremist;
  int8_t frank_evasive = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Frank] = frank_evasive;
  personality_attributes[personality::EPERSONALITY_Evasive] = his_gen::ATTRIBUTE_MAX - frank_evasive;
  int8_t generous_selfish = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Generous] = generous_selfish;
  personality_attributes[personality::EPERSONALITY_Selfish] = his_gen::ATTRIBUTE_MAX - generous_selfish;
  int8_t jealous_compassionate = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Jealous] = jealous_compassionate;
  personality_attributes[personality::EPERSONALITY_Compassionate] = his_gen::ATTRIBUTE_MAX - jealous_compassionate;
  int8_t placid_excitable = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Placid] = placid_excitable;
  personality_attributes[personality::EPERSONALITY_Excitable] = his_gen::ATTRIBUTE_MAX - placid_excitable;
  int8_t thoughtful_rash = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Thoughtful] = thoughtful_rash;
  personality_attributes[personality::EPERSONALITY_Rash] = his_gen::ATTRIBUTE_MAX - thoughtful_rash;
  int8_t thrifty_extravagant = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Thrifty] = thrifty_extravagant;
  personality_attributes[personality::EPERSONALITY_Extravagant] = his_gen::ATTRIBUTE_MAX - thrifty_extravagant;
  int8_t argumentative_amiable = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Argumentative] = argumentative_amiable;
  personality_attributes[personality::EPERSONALITY_Amiable] = his_gen::ATTRIBUTE_MAX - argumentative_amiable;
  int8_t witty_humorless = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Witty] = witty_humorless;
  personality_attributes[personality::EPERSONALITY_Humorless] = his_gen::ATTRIBUTE_MAX - witty_humorless;
  int8_t honest_deceitful = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Honest] = honest_deceitful;
  personality_attributes[personality::EPERSONALITY_Deceitful] = his_gen::ATTRIBUTE_MAX - honest_deceitful;
  int8_t lustful_chaste = his_gen::dice::Make_a_roll<int8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Lustful] = lustful_chaste;
  personality_attributes[personality::EPERSONALITY_Chaste] = his_gen::ATTRIBUTE_MAX - lustful_chaste;

  return personality_attributes;
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json, const his_gen::Personality& personality)
{
  nlohmann::json attributes_converted;
  Personality::Personality_attribute_map attributes = personality.Get_attributes();
  for(auto it = attributes.begin(); it != attributes.end(); ++it)
  {
    attributes_converted[his_gen::Attribute_enums::Get_entity_attribute_string(it->first)] = it->second;
  }

  json = nlohmann::json
  {
    {"attributes", attributes_converted}
  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json, his_gen::Personality& personality)
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
