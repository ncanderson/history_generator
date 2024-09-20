/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs

// Application files
#include <utils/history_generator_utils.h>
#include <data_access/data_access_dao_pg.h>

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_dao_pg::Data_access_dao_pg(const DAL_PG_params& params)
    :
    Data_access_dao_base()
{

}

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_dao_pg::~Data_access_dao_pg()
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_pg::Write_history(his_gen::Generated_history& generated_history)
{
  his_gen::Print_to_cout("PG, entity size: " + std::to_string(generated_history.Entities.size()));
}

///////////////////////////////////////////////////////////////////////

his_gen::Data_definitions his_gen::Data_access_dao_pg::Load_data_definitions()
{
  return his_gen::Data_definitions();
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_pg::Load_all_names(std::vector<std::string>& names,
                                                 std::vector<std::string>& titles)
{
  his_gen::Print_to_cout("Load_all_names");
}

///////////////////////////////////////////////////////////////////////

// END OF FILE
