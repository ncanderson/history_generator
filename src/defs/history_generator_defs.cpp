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

std::string his_gen::Get_entity_type_string(const his_gen::EEntity_type& entity_type)
{
  switch(entity_type)
  {
    //case EENTITY_TYPE_Artifact:    return "artifact";
    //case EENTITY_TYPE_Beast:       return "beast";
    //case EENTITY_TYPE_Clan_tribe:  return "clan/tribe";
    //case EENTITY_TYPE_Culture:     return "culture";
    case EENTITY_TYPE_Deity:       return "deity";
    //case EENTITY_TYPE_Ethnicity:   return "ethnicity";
    //case EENTITY_TYPE_Event:       return "event";
    //case EENTITY_TYPE_Faction:     return "faction";
    //case EENTITY_TYPE_House:       return "house";
    //case EENTITY_TYPE_Idea:        return "idea";
    //case EENTITY_TYPE_Institution: return "institution";
    //case EENTITY_TYPE_Language:    return "language";
    //case EENTITY_TYPE_Legend:      return "legend";
    //case EENTITY_TYPE_Monster:     return "monster";
    //case EENTITY_TYPE_Nation:      return "nation";
    //case EENTITY_TYPE_Order:       return "order";
    //case EENTITY_TYPE_Pantheon:    return "pantheon";
    //case EENTITY_TYPE_Phenomenon:  return "phenomenon";
    //case EENTITY_TYPE_Region:      return "region";
    //case EENTITY_TYPE_Religion:    return "religion";
    //case EENTITY_TYPE_Ruin:        return "ruin";
    case EENTITY_TYPE_Sentient:    return "sentient";
    //case EENTITY_TYPE_Settlement:  return "settlement";
    default:
      throw std::invalid_argument("Entity type not found");
  }
}


///////////////////////////////////////////////////////////////////////

his_gen::EEntity_type his_gen::Get_entity_type(const std::string& entity_type)
{
  static const std::unordered_map<std::string, EEntity_type> entity_type_map =
  {
    {"sentient",    EENTITY_TYPE_Sentient},
    {"deity",       EENTITY_TYPE_Deity},
    //{"beast",       EENTITY_TYPE_Beast},
    //{"monster",     EENTITY_TYPE_Monster},
    //{"clan/tribe",  EENTITY_TYPE_Clan_tribe},
    //{"faction",     EENTITY_TYPE_Faction},
    //{"nation",      EENTITY_TYPE_Nation},
    //{"settlement",  EENTITY_TYPE_Settlement},
    //{"religion",    EENTITY_TYPE_Religion},
    //{"artifact",    EENTITY_TYPE_Artifact},
    //{"region",      EENTITY_TYPE_Region},
    //{"order",       EENTITY_TYPE_Order},
    //{"institution", EENTITY_TYPE_Institution},
    //{"house",       EENTITY_TYPE_House},
    //{"ethnicity",   EENTITY_TYPE_Ethnicity},
    //{"culture",     EENTITY_TYPE_Culture},
    //{"language",    EENTITY_TYPE_Language},
    //{"ruin",        EENTITY_TYPE_Ruin},
    //{"phenomenon",  EENTITY_TYPE_Phenomenon},
    //{"pantheon",    EENTITY_TYPE_Pantheon},
    //{"idea",        EENTITY_TYPE_Idea},
    //{"legend",      EENTITY_TYPE_Legend},
    //{"event",       EENTITY_TYPE_Event}
  };

  const std::string lc_entity_type = his_gen::To_lowercase(entity_type);

  auto it = entity_type_map.find(lc_entity_type);
  if (it != entity_type_map.end())
  {
    return it->second;
  }
  else
  {
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
  static const std::unordered_map<std::string,
                                  ERelationship_type> relationship_type_map =
  {
    {"marriage",   ERELATIONSHIP_TYPE_Marriage},
    {"lover",      ERELATIONSHIP_TYPE_Lover},
    {"conflict",   ERELATIONSHIP_TYPE_Conflict},
    {"parentage",  ERELATIONSHIP_TYPE_Parentage},
    {"dominance",  ERELATIONSHIP_TYPE_Dominance},
    {"friendship", ERELATIONSHIP_TYPE_Friendship},
    {"ownership",  ERELATIONSHIP_TYPE_Ownership},
    {"membership", ERELATIONSHIP_TYPE_Membership}
  };

  const std::string lc_relationship_type = his_gen::To_lowercase(relationship_type);

  auto it = relationship_type_map.find(lc_relationship_type);
  if (it != relationship_type_map.end())
  {
    return it->second;
  }
  else
  {
    his_gen::Print_to_cout(lc_relationship_type);
    throw std::invalid_argument("Can't find relationship type from string");
  }
}

///////////////////////////////////////////////////////////////////////
