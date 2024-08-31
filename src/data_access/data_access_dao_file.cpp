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

his_gen::Data_access_dao_file::~Data_access_dao_file()
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_file::Write_history(std::shared_ptr<models::Generated_history> generated_history)
{
  his_gen::Print_to_cout("FILE, entity size: " + std::to_string(generated_history->Entities.size()));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
