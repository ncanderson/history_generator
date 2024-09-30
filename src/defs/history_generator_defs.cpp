/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libraries
#include <stdexcept>

// Application files
#include <defs/history_generator_defs.h>

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
// END OF FILE
