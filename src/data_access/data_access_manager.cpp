/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libraries

// Application files
#include <data_access/data_access_manager.h>
#include <data_access/data_access_dao_file.h>
#include <data_access/data_access_dao_pg.h>

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_manager::Data_access_manager(const his_gen::DAL_file_params& params)
  :
    m_txport(new his_gen::Data_access_dao_file(params))
{

}

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_manager::Data_access_manager(const his_gen::DAL_PG_params& params)
    :
    m_txport(new his_gen::Data_access_dao_pg(params))
{

}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_manager::Write_history(std::shared_ptr<models::Generated_history> generated_history)
{
  m_txport->Write_history(generated_history);
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
