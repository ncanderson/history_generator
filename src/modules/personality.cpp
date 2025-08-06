/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/personality.h>

// Application files
#include <utils/dice_rolls.h>

///////////////////////////////////////////////////////////////////////

his_gen::Personality::Personality()
    :
    m_personality_attributes()
{
  construct_personality_attributes();
};


///////////////////////////////////////////////////////////////////////

std::string his_gen::Personality::Get_attribute_string(const Personality_attribute personality_attribute)
{
  switch(personality_attribute)
  {
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Aggressive:    return "aggressive";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Passive:       return "passive";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Ambitious:     return "ambitious";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Content:       return "content";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Avoidant:      return "avoidant";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Sociable:      return "sociable";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Brave:         return "brave";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Cowardly:      return "cowardly";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Cooperative:   return "cooperative";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Difficult:     return "difficult";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Cruel:         return "cruel";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Kind:          return "kind";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Decisive:      return "decisive";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Indecisive:    return "indecisive";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Diligent:      return "diligent";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Lazy:          return "lazy";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Flexible:      return "flexible";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Extremist:     return "extremist";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Frank:         return "frank";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Evasive:       return "evasive";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Generous:      return "generous";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Selfish:       return "selfish";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Jealous:       return "jealous";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Compassionate: return "compassionate";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Placid:        return "placid";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Excitable:     return "excitable";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Thoughtful:    return "thoughtful";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Rash:          return "rash";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Thrifty:       return "thrifty";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Extravagant:   return "extravagant";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Argumentative: return "argumentative";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Amiable:       return "amiable";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Witty:         return "witty";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Humorless:     return "humorless";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Honest:        return "honest";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Deceitful:     return "deceitful";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Lustful:       return "lustful";
    case Personality_attribute::PERSONALITY_ATTRIBUTE_Chaste:        return "chaste";
    default:
      // Unrecognized value
      throw std::invalid_argument("Attribute not found");
  }
}

///////////////////////////////////////////////////////////////////////

void his_gen::Personality::construct_personality_attributes()
{
  int8_t aggressive_passive = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Aggressive] = aggressive_passive;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Passive] = 100 - aggressive_passive;
  int8_t ambitious_content = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Ambitious] = ambitious_content;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Content] = 100 - ambitious_content;
  int8_t avoidant_sociable = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Avoidant] = avoidant_sociable;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Sociable] = 100 - avoidant_sociable;
  int8_t brave_cowardly = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Brave] = brave_cowardly;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Cowardly] = 100 - brave_cowardly;
  int8_t cooperative_difficult = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Cooperative] = cooperative_difficult;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Difficult] = 100 - cooperative_difficult;
  int8_t cruel_kind = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Cruel] = cruel_kind;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Kind] = 100 - cruel_kind;
  int8_t decisive_indecisive = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Decisive] = decisive_indecisive;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Indecisive] = 100 - decisive_indecisive;
  int8_t diligent_lazy = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Diligent] = diligent_lazy;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Lazy] = 100- diligent_lazy;
  int8_t flexible_extremist = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Flexible] = flexible_extremist;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Extremist] = 100 - flexible_extremist;
  int8_t frank_evasive = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Frank] = frank_evasive;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Evasive] = 100 - frank_evasive;
  int8_t generous_selfish = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Generous] = generous_selfish;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Selfish] = 100 - generous_selfish;
  int8_t jealous_compassionate = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Jealous] = jealous_compassionate;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Compassionate] = 100 - jealous_compassionate;
  int8_t placid_excitable = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Placid] = placid_excitable;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Excitable] = 100 - placid_excitable;
  int8_t thoughtful_rash = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Thoughtful] = thoughtful_rash;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Rash] = 100 - thoughtful_rash;
  int8_t thrifty_extravagant = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Thrifty] = thrifty_extravagant;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Extravagant] = 100 - thrifty_extravagant;
  int8_t argumentative_amiable = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Argumentative] = argumentative_amiable;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Amiable] = 100 - argumentative_amiable;
  int8_t witty_humorless = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Witty] = witty_humorless;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Humorless] = 100 - witty_humorless;
  int8_t honest_deceitful = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Honest] = honest_deceitful;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Deceitful] = 100 - honest_deceitful;
  int8_t lustful_chaste = his_gen::dice::Make_a_roll<int8_t>(100);
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Lustful] = lustful_chaste;
  m_personality_attributes[Personality_attribute::PERSONALITY_ATTRIBUTE_Chaste] = 100 - lustful_chaste;
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json, const his_gen::Personality& personality)
{
  nlohmann::json attributes_converted;
  Personality::Personality_attribute_map attributes = personality.Get_attributes();
  for(auto it = attributes.begin(); it != attributes.end(); ++it)
  {
    attributes_converted[his_gen::Personality::Get_attribute_string(it->first)] = it->second;
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
