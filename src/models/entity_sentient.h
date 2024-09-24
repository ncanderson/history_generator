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
  Entity_sentient(std::string name, std::string title = "");

  /**
   * @brief Destructor
   */
  ~Entity_sentient(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Entity

/**
 * @brief to_json
 * @param json
 * @param entity
 */
void to_json(nlohmann::json& json, const his_gen::Entity_sentient& entity_sentient);

/**
 * @brief from_json
 * @param json
 * @param entity
 */
void from_json(const nlohmann::json& json, his_gen::Entity_sentient& entity_sentient);

}  // namespace his_gen

#endif // ENTITY_SENTIENT_H
