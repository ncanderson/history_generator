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

/**
 * @brief adl_serializer for a map with a boost UUID as a key
 */
template <typename T, typename Compare, typename Alloc>
struct adl_serializer<std::map<boost::uuids::uuid, T, Compare, Alloc>>
{
  /**
   * @brief to_json
   * @param j
   * @param m
   */
  static void to_json(json& j, const std::map<boost::uuids::uuid, T, Compare, Alloc>& m)
  {
    j = json::object();
    for (const auto& [uuid, value] : m)
    {
      // uses T's to_json function
      j[boost::uuids::to_string(uuid)] = value;
    }
  }

  /**
   * @brief from_json
   * @param j
   * @param m
   */
  static void from_json(const json& j, std::map<boost::uuids::uuid, T, Compare, Alloc>& m)
  {
    m.clear();
    for (auto it = j.begin(); it != j.end(); ++it)
    {
      boost::uuids::uuid id = boost::uuids::string_generator()(it.key());
      // uses T's from_json
      m[id] = it.value().get<T>();
    }
  }
}; // adl_serializer<std::map<boost::uuids::uuid, T, Compare, Alloc>>

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

/**
 * @brief Macro to allow static registration of all Polymorphic types
 * @details This macro will also register the derived type with the
 * Polymorphic_serializer_registry, allowing a single call to register all
 * derived types at startup.
 * @param Base_type The base class to register with
 * @param Derived_type The derived class to register
 */
#define REGISTER_POLYMORPHIC_TYPE(Base_type, Derived_type) \
namespace \
{ \
  using _derived_type_alias = Derived_type; \
  inline void __register_##_derived_type_alias() \
  { \
    static struct __registrar \
    { \
      __registrar() \
      { \
        static_assert(std::is_base_of_v<Base_type, Derived_type>, #Derived_type " must derive from " #Base_type); \
        Polymorphic_serializer<Base_type>::register_types<Derived_type>(); \
      } \
    } registrar_instance; \
  } \
  struct __auto_register_##_derived_type_alias \
  { \
    __auto_register_##_derived_type_alias() \
    { \
      static auto& registry = Polymorphic_serializer_registry::instance().functions; \
    registry.push_back(&__register_##_derived_type_alias); \
    } \
  }; \
  static __auto_register_##_derived_type_alias __auto_register_instance_##_derived_type_alias; \
}

/**
 * @brief Struct to allow automatic registration of derived class with the
 * polymorphic serializer
 */
struct Polymorphic_serializer_registry
{
  /**
   * @brief A vector of functions, that will be used to register polymorphic types
   */
  std::vector<void(*)()> functions;

  /**
   * @brief Get an instance of a derived class to register
   * @return
   */
  static Polymorphic_serializer_registry& instance()
  {
    static Polymorphic_serializer_registry inst;
    return inst;
  }

  /**
   * @brief Initialize all derived types, registering class with the serializer
   */
  void initialize_all()
  {
    for (auto f : functions)
      f();
  }
};


#endif // JSON_HELPER_DEFS_H
