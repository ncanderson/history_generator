/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs

// Application files
#include <utils/history_generator_utils.h>
#include <data_access/data_access_dao_file.h>

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_dao_file::Data_access_dao_file(const DAL_file_params& params)
    :
    Data_access_dao_base()
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_file::Create_entity()
{
  his_gen::Print_to_cout("create entity");
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_file::Test_write()
{
  his_gen::Print_to_cout("in Test_write, file");
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
