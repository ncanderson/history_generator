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
// END OF FILE
