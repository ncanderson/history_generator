// Standard libs
#include <iostream>
#include <chrono>
#include <csignal>
#include <thread>

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
  std::cout<< "Signal " << signal << " caught..." << std::endl;
  m_application_quit = true;
};

///////////////////////////////////////////////////////////////////////
// Main
///////////////////////////////////////////////////////////////////////

int main()
{
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

