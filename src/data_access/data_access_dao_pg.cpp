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

void his_gen::Data_access_dao_pg::Write_history(models::Generated_history generated_history)
{
  his_gen::Print_to_cout("PG, entity size: " + std::to_string(generated_history.Entities.size()));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
