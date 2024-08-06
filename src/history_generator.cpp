// Standard libs
#include <chrono>
#include <csignal>
#include <thread>
#include <boost/program_options.hpp>

#include<iostream>

// Application files
#include <utils/history_manager_utils.h>
#include <history_generator_manager.h>

///////////////////////////////////////////////////////////////////////
// Global Variables
///////////////////////////////////////////////////////////////////////

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
// Main
///////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  //////////////////////////////////////////////////////
  // Set up the program options
  namespace po = boost::program_options;
  // Declare the supported options.
  po::options_description desc("Application options");
  desc.add_options()
      ("help", "Produce help message")
      ("compression", po::value<int>(), "set compression level");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help")) {
    //his_gen::Print_to_cout(desc);
    std::cout << desc << "\n";
    return 1;
  }

  //if (vm.count("compression"))
  //{
  //  cout << "Compression level was set to "
  //       << vm["compression"].as<int>() << ".\n";
  //}
  //else
  //{
  //  cout << "Compression level was not set.\n";
  //}

  // Initialize Manager
  his_gen::History_generator_manager mngr = his_gen::History_generator_manager();

  // Handle SIGINT
  std::signal(SIGINT, &handle_sigint);

  // Run until and unless application receives SIGINT
  while(!m_application_quit && m_generation_era != his_gen::Era::ERA_Terminate)
  {
    try
    {
      m_generation_era = mngr.Run();
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

