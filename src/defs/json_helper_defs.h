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
 * @brief Implementation of the polymorphic JSON serializer
 * @details Taken [from here](https://stackoverflow.com/questions/64349490/is-there-a-way-to-serialize-a-heterogenous-vector-with-nlohmann-json-lib)
 */
namespace Polymorphic_serializer_impl
{
/**
 * @brief The Serializer struct
 */
template <class Base>
struct Serializer
{
  void (*to_json)(nlohmann::json &j, Base const &o);
  void (*from_json)(nlohmann::json const &j, Base &o);
}; // struct Serializer

/**
 * @brief serializer_for
 * @return
 */
template <class Base, class Derived>
Serializer<Base> serializer_for()
{
  return
  {
    [](nlohmann::json &j, Base const &o)
    {
      return to_json(j, static_cast<Derived const &>(o));
    },
    [](nlohmann::json const &j, Base &o)
    {
      return from_json(j, static_cast<Derived &>(o));
    }
  };
}

} // namespace Polymorphic_serializer_impl

template <class Base>
struct Polymorphic_serializer
{
  /**
   * @brief _serializers Maps typeid(x).name() to the from/to serialization
   * functions
   */
  static inline std::unordered_map<char const *,
                                   Polymorphic_serializer_impl::Serializer<Base>> _serializers;

  /**
   * @brief Register types with the serializer
   */
  template <class... Derived>
  static void register_types()
  {
    (_serializers.emplace(typeid(Derived).name(),
                          Polymorphic_serializer_impl::serializer_for<Base, Derived>()),
     ...);
  }

  /**
   * @brief to_json
   * @param j
   * @param o
   */
  static void to_json(nlohmann::json &j, Base const &o)
  {
    char const *typeName = typeid(o).name();
    _serializers.at(typeName).to_json(j, o);
    j["_type"] = typeName;
  }

  /**
   * @brief from_json
   * @param j
   * @param o
   */
  static void from_json(nlohmann::json const &j, Base &o)
  {
    _serializers.at(j.at("_type").get<std::string>().c_str()).from_json(j, o);
  }
}; // struct Polymorphic_serializer

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
  static void to_json(json& j, const std::shared_ptr<T>& opt)
  {
    if (opt)
    {
      j = *opt;
    }
    else
    {
      j = nullptr;
    }
  }

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

/**
 * @brief The adl_serializer extention for the Entity_base class, allowing
 * serialization of classes derived from it.
 */
template <>
struct adl_serializer<his_gen::Entity_base>
    :
    Polymorphic_serializer<his_gen::Entity_base>
{
};

} // namespace nlohmann

#endif // JSON_HELPER_DEFS_H
