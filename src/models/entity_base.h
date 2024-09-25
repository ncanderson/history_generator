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
   * @brief Constructor.
   */
  Entity_base(std::string name, std::string title = "");

  /**
   * @brief Destructor
   */
  ~Entity_base(){};

  void Set_name(std::string name) {m_name = name;}
  std::string Get_name() const {return m_name;}
  void Set_title(std::string title) {m_title=title;}
  std::string Get_title() const {return m_title;}

  //NLOHMANN_DEFINE_TYPE_INTRUSIVE(Entity_base, m_name, m_title)

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

void to_json(nlohmann::json& json, const std::shared_ptr<his_gen::Entity_base>& entity_base);

/**
 * @brief from_json
 * @param json
 * @param entity_base
 */
void from_json(const nlohmann::json& json, his_gen::Entity_base& entity_base);

}  // namespace his_gen

#endif // ENTITY_BASE_H
