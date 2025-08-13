/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/names.h>
#include <utils/dice_rolls.h>

std::vector<std::string> his_gen::Names::m_names;
std::vector<std::string> his_gen::Names::m_titles;

///////////////////////////////////////////////////////////////////////

void his_gen::Names::Initialize(const his_gen::Data_access_manager& data_access_manager)
{
  data_access_manager.Load_all_names(m_names, m_titles);
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Names::Get_one_name()
{
  // Commenting for now. There will be a generator at some point, but popping
  // from this list will cause segfaults when we run out of space
  //std::string name = m_names.back();
  //m_names.pop_back();

  return his_gen::dice::Get_random_element(m_names);
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Names::Get_one_title()
{
  // Commenting for now. There will be a generator at some point, but popping
  // from this list will cause segfaults when we run out of space
  //std::string title = m_titles.back();
  //m_titles.pop_back();

  return his_gen::dice::Get_random_element(m_titles);
}

///////////////////////////////////////////////////////////////////////
