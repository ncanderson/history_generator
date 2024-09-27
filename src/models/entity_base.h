/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>
#include <defs/json_helper_defs.h>

// Application files
#include <utils/history_generator_utils.h>

namespace his_gen
{
/**
 * @brief Base class for generated entities
 */
class Entity_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   */
  Entity_base(std::string name, std::string title = "")
      :
      m_name(name),
      m_title(title)
  { };

  /**
   * @brief Virtual destructor.
   */
  virtual ~Entity_base() = default;

  /**
   * @brief Set_name
   * @param name
   */
  void Set_name(std::string name) { m_name = name; }

  /**
   * @brief Get_name
   * @return
   */
  std::string Get_name() const { return m_name; }

  /**
   * @brief Set_title
   * @param title
   */
  void Set_title(std::string title) { m_title=title; }

  /**
   * @brief Get_title
   * @return
   */
  std::string Get_title() const { return m_title; }

protected:
  // Attributes
  /**
   * @brief Entity name
   */
  std::string m_name;

  /**
   * @brief Entity title
   */
  std::string m_title;

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Entity_base

/**
 * @brief to_json
 * @param json
 * @param entity_base
 */
void to_json(nlohmann::json& json, const his_gen::Entity_base& entity_base);

/**
 * @brief from_json
 * @param json
 * @param entity_base
 */
void from_json(const nlohmann::json& json, his_gen::Entity_base& entity_base);

}  // namespace his_gen

/**
 * By extending the adl_serializer to utilize this class, we can register
 * derived classed allowing us to serialize those classes to JSON
 */
namespace nlohmann
{
template <>
struct adl_serializer<his_gen::Entity_base>
    :
    Polymorphic_serializer<his_gen::Entity_base>{ };
} // namespace nlohmann

#endif // ENTITY_BASE_H
