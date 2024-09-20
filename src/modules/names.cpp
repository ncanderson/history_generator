/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/names.h>

///////////////////////////////////////////////////////////////////////

his_gen::Names::Names(const his_gen::Data_access_manager& data_access_manager)
    :
    m_data_access_manager(data_access_manager),
    m_names()
{
  load_all_names(m_names, m_titles);
}

///////////////////////////////////////////////////////////////////////

void his_gen::Names::load_all_names(std::vector<std::string>& names,
                                    std::vector<std::string>& titles)
{
  m_data_access_manager.Load_all_names(names, titles);
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Names::Get_one_name()
{
  std::string name = m_names.back();
  m_names.pop_back();
  return name;
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Names::Get_one_title()
{
  std::string title = m_titles.back();
  m_titles.pop_back();
  return title;
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
