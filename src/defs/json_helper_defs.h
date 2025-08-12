/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef JSON_HELPER_DEFS_H
#define JSON_HELPER_DEFS_H

// Standard libraries
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>

// JSON
#include <deps/json.hpp>

// Application files
#include <defs/history_generator_defs.h>
#include <modules/personality.h>

/**
 * @brief Extension of nlohmann namespace for additional serializers to handle
 * polymorphism and additional data types
 */
namespace nlohmann
{

//// TODO Do I need this? I didn't do this for the phsicality attrs but it still worked
///**
// * @brief Adl_serializer for maps with Personality attribute keys
// */
//template <typename T>
//struct adl_serializer<std::map<his_gen::Personality::Personality_attribute, T>>
//{
//  using Map = std::map<his_gen::Personality::Personality_attribute, T>;
//
//  /**
//   * @brief to_json
//   * @param json
//   * @param map
//   */
//  static void to_json(json& json, Map const& map)
//  {
//    for(auto it = map.begin(); it != map.end(); ++it)
//    {
//      json[his_gen::Personality::Get_attribute_string(it->first)] = it->second;
//    }
//  }
//};

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
  static void to_json(json &j, const std::shared_ptr<T>& opt)
  {
    if (opt)
    {
      j = *opt.get();
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

}; // struct adl_serializer: std::shared_ptr<T>

/**
 * @brief Adl_serializer for boost UUIDs
 */
template <>
struct adl_serializer<boost::uuids::uuid>
{
  /**
   * @brief to_json
   * @param j
   * @param id
   */
  static void to_json(json& j, const boost::uuids::uuid& id)
  {
    j = boost::uuids::to_string(id);
  }

  /**
   * @brief from_json
   * @param j
   * @param id
   */
  static void from_json(const json& j, boost::uuids::uuid& id)
  {
    boost::uuids::string_generator gen;
    id = gen(j.get<std::string>());
  }
}; // struct adl_serializer: boost::uuids::uuid

}  // namespace nlohmann

/**
 * @brief Polymorphic JSON serializer implementation. This will allow full
 * serialization of types used polymorphically.
 */
namespace Polymorphic_serializer_impl
{
/**
 * @brief The Serializer class
 */
template <class Base>
struct Serializer
{
  void (*to_json)(nlohmann::json &j, Base const &o);
  void (*from_json)(nlohmann::json const &j, Base &o);
};

/**
 * @brief serializerFor
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

/**
 * @brief The Polymorphic_serializer class
 */
template <class Base>
struct Polymorphic_serializer
{
  /**
   * @brief Maps typeid(x).name() to the from/to serialization functions
   */
  static inline std::unordered_map<char const *,
                                   Polymorphic_serializer_impl::Serializer<Base>> _serializers;

  /**
   * @brief register_types
   */
  template <class... Derived>
  static void register_types()
  {
    (_serializers.emplace(typeid(Derived).name(),
                                 Polymorphic_serializer_impl::serializer_for<Base, Derived>()), ...);
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

#endif // JSON_HELPER_DEFS_H
