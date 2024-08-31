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
#include <history_generator_manager.h>
#include <data_access/data_access_manager.h>
#include <utils/history_generator_root_config.h>

// Data access layer
#include <data_access/data_access_dao_base.h>
#include <data_access/data_access_dao_file.h>
#include <data_access/data_access_dao_pg.h>
#include <models/generated_history.h>

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

/**
 * @brief Application configuration
 */
std::shared_ptr<his_gen::History_generator_root_config> m_app_cfg;

/**
 * @brief The history being generated
 */
std::shared_ptr<models::Generated_history> m_generated_history;

/**
 * @brief Runtime data access manager
 */
std::shared_ptr<his_gen::Data_access_manager> m_data_access_manager;

/**
 * @brief History generator manager
 */
std::shared_ptr<his_gen::History_generator_manager> m_his_gen_mngr;

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

/**
 * @brief Instantiate data access manager based on data access type
 * @param data_access_type Enumerated data access type
 * @throws std::exception Thrown if the data access type is 'unknown'
 */
void initialize_data_access(his_gen::Data_access_type data_access_type)
{
  switch(data_access_type)
  {
    case his_gen::DATA_ACCESS_TYPE_File:
    {
      his_gen::DAL_file_params file_params = his_gen::DAL_file_params();
      m_data_access_manager = std::make_shared<his_gen::Data_access_manager>(file_params);
    }
    break;
    case his_gen::DATA_ACCESS_TYPE_Postgres:
    {
      his_gen::DAL_PG_params pg_params = his_gen::DAL_PG_params();
      m_data_access_manager = std::make_shared<his_gen::Data_access_manager>(pg_params);
    }
    break;
    case his_gen::DATA_ACCESS_TYPE_Unknown:
    {
      throw std::exception();
    }
  }
}

///////////////////////////////////////////////////////////////////////

void validate_json_config(std::shared_ptr<his_gen::History_generator_root_config> app_config)
{
  // ensure data access type is file or postgres

  // more steps as we learn them
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

  // Declare the supported options.
  po::options_description desc("Application options");
  desc.add_options()
      ("help", "Produce help message")
      ("app_cfg", po::value(&app_cfg)->default_value(app_cfg), "Main application config file");

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
  if(vm.count("app_cfg"))
  {
    try
    {
      std::ifstream app_cfg_file(app_cfg);
      json data = json::parse(app_cfg_file);
      m_app_cfg.reset(new his_gen::History_generator_root_config(data));
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

  validate_json_config(m_app_cfg);

  //////////////////////////////////////////////////////
  // Set up Runtime Objects

  // Initialize data repository
  m_generated_history.reset(new models::Generated_history());

  // Set up data access manager
  initialize_data_access(his_gen::Get_data_access_type_from_string(m_app_cfg->Data_access_type));

  // Initialize Runtime Manager
  m_his_gen_mngr.reset(new his_gen::History_generator_manager(m_app_cfg,
                                                              m_generated_history,
                                                              m_data_access_manager));

  // Run until and unless application receives SIGINT
  while(!m_application_quit && m_generation_era != his_gen::Era::ERA_Terminate)
  {
    try
    {
      m_generation_era = m_his_gen_mngr->Run();
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

