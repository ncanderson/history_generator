#ifndef HISTORY_GENERATOR_UTILS_H
#define HISTORY_GENERATOR_UTILS_H

#include <string>
#include <iostream>

namespace his_gen
{

/**
 * @brief Print the argued error message to the console
 * @param log_message The message to print
 */
void Print_to_cout(std::string log_message);

/**
 * @brief Print key value pair
 * @tparam T The numeric class to print
 * @param key_name Name of key
 * @param value Value associated with key
 */
template <typename T>
void Print_key_value(std::string key_name, T value)
{
  std::cout << "Log Message: " << key_name << " : " << std::to_string(value) << std::endl;
}

}  // namespace his_gen

#endif // HISTORY_GENERATOR_UTILS_H
