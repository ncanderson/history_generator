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

  uint8_t aggressive_passive = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Aggressive] = aggressive_passive;
  personality_attributes[personality::EPERSONALITY_Passive] = his_gen::ATTRIBUTE_MAX - aggressive_passive;
  uint8_t ambitious_content = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Ambitious] = ambitious_content;
  personality_attributes[personality::EPERSONALITY_Content] = his_gen::ATTRIBUTE_MAX - ambitious_content;
  uint8_t avoidant_sociable = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Avoidant] = avoidant_sociable;
  personality_attributes[personality::EPERSONALITY_Sociable] = his_gen::ATTRIBUTE_MAX - avoidant_sociable;
  uint8_t brave_cowardly = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Brave] = brave_cowardly;
  personality_attributes[personality::EPERSONALITY_Cowardly] = his_gen::ATTRIBUTE_MAX - brave_cowardly;
  uint8_t cooperative_difficult = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Cooperative] = cooperative_difficult;
  personality_attributes[personality::EPERSONALITY_Difficult] = his_gen::ATTRIBUTE_MAX - cooperative_difficult;
  uint8_t cruel_kind = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Cruel] = cruel_kind;
  personality_attributes[personality::EPERSONALITY_Kind] = his_gen::ATTRIBUTE_MAX - cruel_kind;
  uint8_t decisive_indecisive = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Decisive] = decisive_indecisive;
  personality_attributes[personality::EPERSONALITY_Indecisive] = his_gen::ATTRIBUTE_MAX - decisive_indecisive;
  uint8_t diligent_lazy = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Diligent] = diligent_lazy;
  personality_attributes[personality::EPERSONALITY_Lazy] = his_gen::ATTRIBUTE_MAX - diligent_lazy;
  uint8_t flexible_extremist = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Flexible] = flexible_extremist;
  personality_attributes[personality::EPERSONALITY_Extremist] = his_gen::ATTRIBUTE_MAX - flexible_extremist;
  uint8_t frank_evasive = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Frank] = frank_evasive;
  personality_attributes[personality::EPERSONALITY_Evasive] = his_gen::ATTRIBUTE_MAX - frank_evasive;
  uint8_t generous_selfish = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Generous] = generous_selfish;
  personality_attributes[personality::EPERSONALITY_Selfish] = his_gen::ATTRIBUTE_MAX - generous_selfish;
  uint8_t jealous_compassionate = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Jealous] = jealous_compassionate;
  personality_attributes[personality::EPERSONALITY_Compassionate] = his_gen::ATTRIBUTE_MAX - jealous_compassionate;
  uint8_t placid_excitable = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Placid] = placid_excitable;
  personality_attributes[personality::EPERSONALITY_Excitable] = his_gen::ATTRIBUTE_MAX - placid_excitable;
  uint8_t thoughtful_rash = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Thoughtful] = thoughtful_rash;
  personality_attributes[personality::EPERSONALITY_Rash] = his_gen::ATTRIBUTE_MAX - thoughtful_rash;
  uint8_t thrifty_extravagant = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Thrifty] = thrifty_extravagant;
  personality_attributes[personality::EPERSONALITY_Extravagant] = his_gen::ATTRIBUTE_MAX - thrifty_extravagant;
  uint8_t argumentative_amiable = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Argumentative] = argumentative_amiable;
  personality_attributes[personality::EPERSONALITY_Amiable] = his_gen::ATTRIBUTE_MAX - argumentative_amiable;
  uint8_t witty_humorless = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Witty] = witty_humorless;
  personality_attributes[personality::EPERSONALITY_Humorless] = his_gen::ATTRIBUTE_MAX - witty_humorless;
  uint8_t honest_deceitful = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Honest] = honest_deceitful;
  personality_attributes[personality::EPERSONALITY_Deceitful] = his_gen::ATTRIBUTE_MAX - honest_deceitful;
  uint8_t lustful_chaste = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Lustful] = lustful_chaste;
  personality_attributes[personality::EPERSONALITY_Chaste] = his_gen::ATTRIBUTE_MAX - lustful_chaste;
  uint8_t romantic_pragmatic = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Romantic] = romantic_pragmatic;
  personality_attributes[personality::EPERSONALITY_Pragmatic] = his_gen::ATTRIBUTE_MAX - romantic_pragmatic;
  uint8_t proud_humble = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Proud] = proud_humble;
  personality_attributes[personality::EPERSONALITY_Humble] = his_gen::ATTRIBUTE_MAX - proud_humble;
  uint8_t forgiving_resentful = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Forgiving] = forgiving_resentful;
  personality_attributes[personality::EPERSONALITY_Resentful] = his_gen::ATTRIBUTE_MAX - forgiving_resentful;
  uint8_t flirtatious_reserved = his_gen::dice::Make_a_roll<uint8_t>(his_gen::ATTRIBUTE_MAX);
  personality_attributes[personality::EPERSONALITY_Flirtatious] = flirtatious_reserved;
  personality_attributes[personality::EPERSONALITY_Reserved] = his_gen::ATTRIBUTE_MAX - flirtatious_reserved;

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
