/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libraries
#include <stdexcept>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <cctype>

// Application files
#include <defs/history_generator_defs.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

std::string his_gen::To_lowercase(const std::string& input_string)
{
  std::string result = input_string;
  std::transform(result.begin(), result.end(), result.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return result;
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_current_era(his_gen::Era current_era)
{
  switch(current_era)
  {
    case ERA_Unknown:   return "Unknown";       break;
    case ERA_Mythology: return "Mythology";     break;
    case ERA_History:   return "History";       break;
    case ERA_End_times: return "End Times";     break;
    case ERA_Terminate: return "Terminate";     break;
    default:            return "Era not found"; break;
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_current_stage(his_gen::Stage current_stage)
{
  switch(current_stage)
  {
    case STAGE_Init:      return "Init";            break;
    case STAGE_Run:       return "Run";             break;
    case STAGE_Terminate: return "Terminate";       break;
    default:              return "Stage not found"; break;
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_data_access_type(Data_access_type data_access_type)
{
  switch (data_access_type)
  {
    case DATA_ACCESS_TYPE_Unknown:  return "Unknown data access type";   break;
    case DATA_ACCESS_TYPE_File:     return "File";                       break;
    case DATA_ACCESS_TYPE_Postgres: return "PostgreSQL RMDS";            break;
    default:                        return "Data access type not found"; break;
  }
}

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_type his_gen::Get_data_access_type(std::string data_access_type)
{
  if(data_access_type == "file")
  {
    return DATA_ACCESS_TYPE_File;
  }
  else if(data_access_type == "postgres")
  {
    return DATA_ACCESS_TYPE_Postgres;
  }
  else
  {
    return DATA_ACCESS_TYPE_Unknown;
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_attribute_string(const his_gen::Attribute attribute)
{
  switch(attribute)
  {
    case ATTRIBUTE_Aggressive:    return "aggressive";
    case ATTRIBUTE_Passive:       return "passive";
    case ATTRIBUTE_Ambitious:     return "ambitious";
    case ATTRIBUTE_Content:       return "content";
    case ATTRIBUTE_Avoidant:      return "avoidant";
    case ATTRIBUTE_Sociable:      return "sociable";
    case ATTRIBUTE_Brave:         return "brave";
    case ATTRIBUTE_Cowardly:      return "cowardly";
    case ATTRIBUTE_Cooperative:   return "cooperative";
    case ATTRIBUTE_Difficult:     return "difficult";
    case ATTRIBUTE_Cruel:         return "cruel";
    case ATTRIBUTE_Kind:          return "kind";
    case ATTRIBUTE_Decisive:      return "decisive";
    case ATTRIBUTE_Indecisive:    return "indecisive";
    case ATTRIBUTE_Diligent:      return "diligent";
    case ATTRIBUTE_Lazy:          return "lazy";
    case ATTRIBUTE_Flexible:      return "flexible";
    case ATTRIBUTE_Extremist:     return "extremist";
    case ATTRIBUTE_Frank:         return "frank";
    case ATTRIBUTE_Evasive:       return "evasive";
    case ATTRIBUTE_Generous:      return "generous";
    case ATTRIBUTE_Selfish:       return "selfish";
    case ATTRIBUTE_Jealous:       return "jealous";
    case ATTRIBUTE_Compassionate: return "compassionate";
    case ATTRIBUTE_Placid:        return "placid";
    case ATTRIBUTE_Excitable:     return "excitable";
    case ATTRIBUTE_Thoughtful:    return "thoughtful";
    case ATTRIBUTE_Rash:          return "rash";
    case ATTRIBUTE_Thrifty:       return "thrifty";
    case ATTRIBUTE_Extravagant:   return "extravagant";
    case ATTRIBUTE_Argumentative: return "argumentative";
    case ATTRIBUTE_Amiable:       return "amiable";
    case ATTRIBUTE_Witty:         return "witty";
    case ATTRIBUTE_Humorless:     return "humorless";
    case ATTRIBUTE_Honest:        return "honest";
    case ATTRIBUTE_Deceitful:     return "deceitful";
    default:
      // Unrecognized value
      throw std::invalid_argument("Attribute not found");
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_entity_type_string(const his_gen::EEntity_type& entity_type)
{
  switch(entity_type)
  {
    case EENTITY_TYPE_Beast:      return "beast";
    case EENTITY_TYPE_Clan_tribe: return "clan/tribe";
    case EENTITY_TYPE_Deity:      return "deity";
    case EENTITY_TYPE_Faction:    return "faction";
    case EENTITY_TYPE_Monster:    return "monster";
    case EENTITY_TYPE_Nation:     return "nation";
    case EENTITY_TYPE_Sentient:   return "sentient";
    default:
      // Unrecognized value
      throw std::invalid_argument("Entity type not found");
  }
}

///////////////////////////////////////////////////////////////////////

his_gen::EEntity_type his_gen::Get_entity_type(const std::string& entity_type)
{
  const std::string lc_entity_type = his_gen::To_lowercase(entity_type);

  if(lc_entity_type == "beast")
  {
    return EENTITY_TYPE_Beast;
  }
  else if(lc_entity_type == "clan/tribe")
  {
    return EENTITY_TYPE_Clan_tribe;
  }
  else if(lc_entity_type == "deity")
  {
    return EENTITY_TYPE_Deity;
  }
  else if(lc_entity_type == "faction")
  {
    return EENTITY_TYPE_Faction;
  }
  else if(lc_entity_type == "monster")
  {
    return EENTITY_TYPE_Monster;
  }
  else if(lc_entity_type == "nation")
  {
    return EENTITY_TYPE_Nation;
  }
  else if(lc_entity_type == "sentient")
  {
    return EENTITY_TYPE_Sentient;
  }
  else
  {
    // Unrecognized value
    his_gen::Print_to_cout(lc_entity_type);
    throw std::invalid_argument("Can't find entity type from string");
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_relationship_type_string(const ERelationship_type& relationship_type)
{
  switch(relationship_type)
  {
    case ERELATIONSHIP_TYPE_Conflict:   return "conflict";
    case ERELATIONSHIP_TYPE_Dominance:  return "dominance";
    case ERELATIONSHIP_TYPE_Friendship: return "friendship";
    case ERELATIONSHIP_TYPE_Lover:      return "lover";
    case ERELATIONSHIP_TYPE_Marriage:   return "marriage";
    case ERELATIONSHIP_TYPE_Membership: return "membership";
    case ERELATIONSHIP_TYPE_Ownership:  return "ownership";
    case ERELATIONSHIP_TYPE_Parentage:  return "parentage";
    default:
      // Unrecognized value
      throw std::invalid_argument("Relationship type not found");
  }
}

///////////////////////////////////////////////////////////////////////

his_gen::ERelationship_type his_gen::Get_relationship_type(const std::string& relationship_type)
{
  const std::string lc_relationship_type = his_gen::To_lowercase(relationship_type);

  if(lc_relationship_type == "marriage")
  {
    return ERELATIONSHIP_TYPE_Marriage;
  }
  else if(lc_relationship_type == "lover")
  {
    return ERELATIONSHIP_TYPE_Lover;
  }
  else if(lc_relationship_type == "conflict")
  {
    return ERELATIONSHIP_TYPE_Conflict;
  }
  else if(lc_relationship_type == "parentage")
  {
    return ERELATIONSHIP_TYPE_Parentage;
  }
  else if(lc_relationship_type == "dominance")
  {
    return ERELATIONSHIP_TYPE_Dominance;
  }
  else if(lc_relationship_type == "friendship")
  {
    return ERELATIONSHIP_TYPE_Friendship;
  }
  else if(lc_relationship_type == "ownership")
  {
    return ERELATIONSHIP_TYPE_Ownership;
  }
  else if(lc_relationship_type == "membership")
  {
    return ERELATIONSHIP_TYPE_Membership;
  }
  else
  {
    // Unrecognized value
    his_gen::Print_to_cout(lc_relationship_type);
    throw std::invalid_argument("Can't find relationship type from string");
  }
}

///////////////////////////////////////////////////////////////////////
