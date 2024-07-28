#include <iostream>
#include <chrono>

/**
 * @brief Main thread sleep interval, ms
 */
const std::chrono::milliseconds m_main_sleep_ms(10);

int main()
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}

