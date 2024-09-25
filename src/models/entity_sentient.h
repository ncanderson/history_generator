/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_SENTIENT_H
#define ENTITY_SENTIENT_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <models/entity_base.h>
#include <utils/history_generator_utils.h>
#include <modules/personality.h>




// look at this for how to instantiate entities using the base class
// https://stackoverflow.com/a/34445588/5543374




namespace his_gen
{
/**
 * @brief A generated entity
 */
class Entity_sentient : public virtual Entity_base
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor
   */
  Entity_sentient(std::string name, std::string title, bool test = true);

  /**
   * @brief Destructor
   */
  ~Entity_sentient(){};

  // temp for testing
  bool Get_test() const { return m_test; }

  void Set_name(std::string name) { m_name = name; }
  std::string Get_name() const { return m_name; }
  void Set_title(std::string title) { m_title = title; }
  std::string Get_title() const { return m_title; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Test var to figure out how to make inheritance work
   */
  bool m_test = false;

  //Personality m_personality;

  // Implementation

}; // class Entity

/**
 * @brief to_json
 * @param json
 * @param entity
 */
void to_json(nlohmann::json& json,
             const his_gen::Entity_sentient& entity_sentient);

/**
 * @brief from_json
 * @param json
 * @param entity
 */
void from_json(const nlohmann::json& json,
               his_gen::Entity_sentient& entity_sentient);

}  // namespace his_gen

#endif // ENTITY_SENTIENT_H
