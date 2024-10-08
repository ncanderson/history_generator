/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef JSON_HELPER_DEFS_H
#define JSON_HELPER_DEFS_H

// Standard libraries
#include <string>

// JSON
#include <deps/json.hpp>

/**
 * Extension of nlohmann namespace for additional serializers to handle
 * polymorphism
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

}; // struct adl_serializer
}  // namespace nlohmann

/**
 * @brief Polymorphic JSON serializer implementation
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
