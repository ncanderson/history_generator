/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

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
   * @brief Constructor
   */
  Entity_base(std::string name, std::string title = ""){};

  /**
   * @brief Destructor
   */
  ~Entity_base(){};

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
  void Set_title(std::string title) { m_title = title; }

  /**
   * @brief Get_title
   * @return
   */
  std::string Get_title() const { return m_title; }

protected:
  // Attributes

  // Implementation

private:
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

}; // class Entity_base

/**
 * @brief to_json
 * @param json
 * @param entity_base
 */
void to_json(nlohmann::json& json, const his_gen::Entity_base& entity_base)
{
  //json = nlohmann::json
  //{
  //  {"name", entity_base.Get_name()},
  //  {"title", entity_base.Get_title()}
  //};
}

/**
 * @brief from_json
 * @param json
 * @param entity_base
 */
void from_json(const nlohmann::json& json, his_gen::Entity_base& entity_base)
{
  //{
  //  entity_base.Set_name(json.at("name"));
  //  entity_base.Set_title(json.at("title"));
  //}
}

}  // namespace his_gen

#endif // ENTITY_BASE_H
