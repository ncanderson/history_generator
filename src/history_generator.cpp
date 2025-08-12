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

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <utils/dice_rolls.h>
#include <history_generator_manager.h>
#include <data_access/data_access_manager.h>
#include <utils/history_generator_root_config.h>

// Data access layer
#include <data_access/data_access_dao_base.h>
#include <data_access/data_access_dao_file.h>
#include <data_access/data_access_dao_pg.h>
#include <models/generated_history.h>
#include <models/data_definitions.h>

///////////////////////////////////////////////////////////////////////
// Global Variables
///////////////////////////////////////////////////////////////////////

// JSON scope helper
using json = nlohmann::json;

/**
 * @brief m_quit If true, quit the application
 */
bool m_application_quit = false;

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

///////////////////////////////////////////////////////////////////////

// TODO: Move this somewhere else I think
/**
 * @brief Instantiate data access manager based on data access type
 * @param data_access_type Enumerated data access type
 * @returns A new data access manager
 * @throws std::exception Thrown if the data access type is 'unknown'
 */
his_gen::Data_access_manager initialize_data_access(const his_gen::Data_access_type data_access_type)
{
  switch(data_access_type)
  {
    case his_gen::DATA_ACCESS_TYPE_File:
    {
      // TODO: declare these elsewhere, as we'll need to populate them from config
      his_gen::DAL_file_params file_params = his_gen::DAL_file_params();
      return his_gen::Data_access_manager(file_params);
    }
    break;
    case his_gen::DATA_ACCESS_TYPE_Postgres:
    {
      // TODO: declare these elsewhere, as we'll need to populate them from config
      his_gen::DAL_PG_params pg_params = his_gen::DAL_PG_params();
      return his_gen::Data_access_manager(pg_params);
    }
    break;
    default:
    {
      throw std::exception();
    }
  }
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
  std::string app_cfg_path = "config/app_config.json";

  //////////////////////////////////////////////////////
  // Set up the program options
  namespace po = boost::program_options;

  // Declare the supported options.
  po::options_description desc("Application options");
  desc.add_options()
      ("help", "Produce help message")
      ("app_cfg", po::value(&app_cfg_path)->default_value(app_cfg_path), "Main application config file");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  //////////////////////////////////////////////////////
  // Parse options
  if(vm.count("help"))
  {
    std::cout << desc << "\n";
    return 1;
  }

  //////////////////////////////////////////////////////
  // Load config
  his_gen::History_generator_root_config app_cfg;

  if(vm.count("app_cfg"))
  {
    try
    {
      std::ifstream app_cfg_file(app_cfg_path);
      json data = json::parse(app_cfg_file);
      app_cfg = his_gen::History_generator_root_config(data);
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

  app_cfg.Validate_config(app_cfg);

  //////////////////////////////////////////////////////
  // Set up Runtime Objects

  // Set up data access manager
  const his_gen::Data_access_type data_access_type = his_gen::Get_data_access_type(app_cfg.Data_access_type);
  const his_gen::Data_access_manager data_access_manager = initialize_data_access(data_access_type);

  // Initialize Runtime Manager
  his_gen::History_generator_manager m_his_gen_mngr(app_cfg,
                                                    data_access_manager);

  // Track the era, as generators finish their work
  his_gen::Era generation_era = his_gen::ERA_Unknown;
  // Thread sleep duration
  const std::chrono::milliseconds main_sleep_ms(10);
  const std::chrono::milliseconds err_sleep_ms(50);

  // Run until and unless application receives SIGINT
  while(!m_application_quit && generation_era != his_gen::Era::ERA_Terminate)
  {
    generation_era = m_his_gen_mngr.Run();
    std::this_thread::sleep_for(main_sleep_ms);
  }

  return 0;
}

