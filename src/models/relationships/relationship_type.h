/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef RELATIONSHIP_TYPE_H
#define RELATIONSHIP_TYPE_H

// Standard libs
#include <string>

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <defs/history_generator_defs.h>

namespace his_gen
{
/**
 * @brief The type of relationship between entities
 */
class Relationship_type
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Default constructor, required for JSON serialization
   */
  Relationship_type() = default;

  /**
   * @brief Constructor
   * @param relationship_type The type of this relationship
   */
  Relationship_type(const his_gen::ERelationship_type& relationship_type);

  /**
   * @brief Destructor
   */
  ~Relationship_type() = default;

  /**
   * Getters and setters
   */
  std::string Get_name() const { return m_name; }
  his_gen::ERelationship_type Get_relationship_type() const { return m_relationship_type; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Relationship type name
   */
  std::string m_name;

  /**
   * @brief Enumerated relationship type
   */
  his_gen::ERelationship_type m_relationship_type;

  // Implementation

}; // class Relationship_type

/**
 * @brief to_json
 * @param json
 * @param relationship_type
 */
void to_json(nlohmann::json& json,
             const his_gen::Relationship_type& relationship_type);

/**
 * @brief from_json
 * @param json
 * @param relationship_type
 */
void from_json(const nlohmann::json& json,
               his_gen::Relationship_type& relationship_type);

}  // namespace his_gen

#endif // RELATIONSHIP_TYPE_H
