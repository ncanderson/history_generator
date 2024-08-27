/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs
#include <chrono>
#include <csignal>
#include <thread>
#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <history_generator_manager.h>
#include <utils/history_generator_root_config.h>

// Data access layer
#include <data_access/data_access_dao_base.h>
#include <data_access/data_access_dao_file.h>

// JSON
#include <deps/json.hpp>

///////////////////////////////////////////////////////////////////////
// Global Variables
///////////////////////////////////////////////////////////////////////

// JSON scope helper
using json = nlohmann::json;

/**
 * @brief Main thread sleep interval, ms
 */
const std::chrono::milliseconds m_main_sleep_ms(10);

/**
 * @brief Error sleep interval, ms
 */
const std::chrono::milliseconds m_err_sleep_ms(50);

/**
 * @brief m_quit If true, quit the application
 */
bool m_application_quit = false;

/**
 * @brief Current era being processed
 */
his_gen::Era m_generation_era;

/**
 * @brief Data access type
 */
std::string m_data_access_type;

///////////////////////////////////////////////////////////////////////
// Function Declarations
///////////////////////////////////////////////////////////////////////

/**
 * @brief Handle SIGINT and exit the application
 */
void handle_sigint(int signal)
{
  his_gen::Print_to_cout("Signal " + std::to_string(signal) + " caught...");
  m_application_quit = true;
};

void parse_data_access_type()
{

}

///////////////////////////////////////////////////////////////////////
// Main
///////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{  
  // Handle SIGINT
  std::signal(SIGINT, &handle_sigint);

  //////////////////////////////////////////////////////
  // Config defaults
  std::string app_cfg = "config/app_config.json";

  //////////////////////////////////////////////////////
  // Set up the program options
  namespace po = boost::program_options;
  his_gen::History_generator_root_config m_app_cfg;

  // Declare the supported options.
  po::options_description desc("Application options");
  desc.add_options()
      ("help", "Produce help message")
      ("app_cfg", po::value(&app_cfg)->default_value(app_cfg), "Main application config file");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if(vm.count("help"))
  {
    std::cout << desc << "\n";
    return 1;
  }

  // Load config
  if(vm.count("app_cfg"))
  {
    try
    {
      std::ifstream app_cfg_file(app_cfg);
      json data = json::parse(app_cfg_file);
      m_app_cfg = his_gen::History_generator_root_config(data);
    }
    catch (const std::exception& e)
    {
      his_gen::Print_to_cout("Error loading config from JSON");
      his_gen::Print_to_cout(e.what());
      return 1;
    }
  }
  else
  {
    // Error, exit
    his_gen::Print_to_cout("No config found, exiting");
    return 1;
  }

  //////////////////////////////////////////////////////
  // Set up Runtime Objects

  // Set up transport


  // Initialize Runtime Manager
  his_gen::History_generator_manager m_his_gen_mngr = his_gen::History_generator_manager(m_app_cfg);

  // Run until and unless application receives SIGINT
  while(!m_application_quit && m_generation_era != his_gen::Era::ERA_Terminate)
  {
    try
    {
      m_generation_era = m_his_gen_mngr.Run();
    }
    // Catch any errors bubbling up from the main run function
    catch(const std::exception& e)
    {
      std::this_thread::sleep_for(m_err_sleep_ms);
    }
    std::this_thread::sleep_for(m_main_sleep_ms);
  }

  return 0;
}

