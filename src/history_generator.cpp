#include <iostream>
#include <chrono>
#include <csignal>
#include <thread>

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

void print_to_cout(std::string log_message)
{
  std::cout << "Log Message:" << log_message << std::endl;
}

///////////////////////////////////////////////////////////////////////
// Main
///////////////////////////////////////////////////////////////////////

int main()
{
  // Handle SIGINT
  std::signal(SIGINT, &handle_sigint);

  while(!m_application_quit)
  {
    try
    {
      print_to_cout("running");
    }
    catch(const std::exception& e)
    {
      std::this_thread::sleep_for(m_err_sleep_ms);
    }

    std::this_thread::sleep_for(m_main_sleep_ms);
  }

  return 0;
}

