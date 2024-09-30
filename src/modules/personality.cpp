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

std::string his_gen::Personality::get_attribute_string(const Attribute attribute)
{
  switch(attribute)
  {
    case ATTRIBUTE_Aggressive_passive:    return "aggressive-passive";
    case ATTRIBUTE_Ambitious_lazy:        return "ambitious-lazy";
    case ATTRIBUTE_Avoidant_sociable:     return "avoidant-sociable";
    case ATTRIBUTE_Brave_cowardly:        return "brave-cowardly";
    case ATTRIBUTE_Cooperative_difficult: return "cooperative-difficult";
    case ATTRIBUTE_Cruel_kind:            return "cruel-kind";
    case ATTRIBUTE_Decisive_indecisive:   return "decisive-indecisive";
    case ATTRIBUTE_Diligent_lazy:         return "diligent-lazy";
    case ATTRIBUTE_Flexible_extremist:    return "flexible-extremist";
    case ATTRIBUTE_Frank_evasive:         return "frank-evasive";
    case ATTRIBUTE_Generous_selfish:      return "generous-selfish";
    case ATTRIBUTE_Helpful_useless:       return "helpful-useless";
    case ATTRIBUTE_Jealous_compassionate: return "jealous-compassionate";
    case ATTRIBUTE_Placid_excitable:      return "placid-excitable";
    case ATTRIBUTE_Thoughtful_rash:       return "thoughtful-rash";
    case ATTRIBUTE_Thrifty_extravagant:   return "thrifty-extravagant";
    case ATTRIBUTE_Truculent_amiable:     return "truculent-amiable";
    case ATTRIBUTE_Witty_humorless:       return "witty-humorless";
    default:
      // Unrecognized value
      throw std::invalid_argument("Attribute not found");
  }
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json, const his_gen::Personality& personality)
{
  json = nlohmann::json
  {

  };
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json, his_gen::Personality& personality)
{

}

///////////////////////////////////////////////////////////////////////
// END OF FILE
