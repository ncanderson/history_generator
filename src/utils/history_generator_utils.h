/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORY_GENERATOR_UTILS_H
#define HISTORY_GENERATOR_UTILS_H

#include <string>
#include <iostream>

namespace his_gen
{

/**
 * @brief Template for print to cout handling anything convertable to a string
 * @param log_message The message to print
 */
template<typename C>
void Print_to_cout(const C& log_message)
{
  if constexpr (std::is_convertible_v<C, std::string>)
  {
    // For anything you can convert directly to std::string
      std::cout << "Log Message: " << log_message << std::endl;
  }
  else
  {
    // Fallback: stream it directly (works for arithmetic, and any type with operator<<)
      std::cout << "Log Message: " << log_message << std::endl;
  }
}

// TODO: figure out a better way to do this, such that the templated version will
// handle it and we don't need a separate function
/**
 * @brief Print key value pair for strings
 * @param key_name Name of key
 * @param value Value associated with key
 */
void Print_key_value_string(std::string key_name, std::string value);

/**
 * @brief Print key value pair
 * @tparam T The numeric class to print
 * @param key_name Name of key
 * @param value Value associated with key
 */
template <typename T>
void Print_key_value(std::string key_name, T value)
{
  std::cout << "Log Message: " << key_name << ": " << std::to_string(value) << std::endl;
}

}  // namespace his_gen

#endif // HISTORY_GENERATOR_UTILS_H
