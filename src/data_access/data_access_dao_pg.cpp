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

void his_gen::Data_access_dao_pg::Create_entity()
{
  his_gen::Print_to_cout("create entity");
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_pg::Test_write()
{
  his_gen::Print_to_cout("in Test_write, postgres");
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
