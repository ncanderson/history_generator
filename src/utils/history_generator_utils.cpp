/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs
#include <iostream>

// Application files
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

void his_gen::Print_to_cout(std::string log_message)
{
  std::cout << "Log Message: " << log_message << std::endl;
}

///////////////////////////////////////////////////////////////////////

void his_gen::Print_key_value_string(std::string key_name, std::string value)
{
  std::cout << "Log Message: " << key_name << " : " << value << std::endl;
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
