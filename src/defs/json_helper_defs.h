/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef JSON_HELPER_DEFS_H
#define JSON_HELPER_DEFS_H

// Standard libraries
#include <string>

// JSON
#include <deps/json.hpp>

// Models
#include <models/entity_base.h>

/**
 * @brief Additional JSON serializers
 */
namespace nlohmann
{
/**
 * @brief Additional serializer for a shared pointer
 */
template <typename T>
struct adl_serializer<std::shared_ptr<T>>
{
  /**
   * @brief to_json
   * @param j
   * @param opt
   */
  //static void to_json(json& j, const std::shared_ptr<T>& opt)
  //{
  //  if (opt)
  //  {
  //    j = *opt.get;
  //  }
  //  else
  //  {
  //    j = nullptr;
  //  }
  //}

  /**
   * @brief from_json
   * @param j
   * @param opt
   */
  static void from_json(const json& j, std::shared_ptr<T>& opt)
  {
    if (j.is_null())
    {
      opt = nullptr;
    }
    else
    {
      opt.reset(new T(j.get<T>()));
    }
  }

}; // struct adl_serializer
}  // namespace nlohmann

#endif // JSON_HELPER_DEFS_H
