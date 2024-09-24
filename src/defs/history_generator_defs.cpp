/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

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
// END OF FILE
