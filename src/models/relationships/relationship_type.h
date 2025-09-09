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
 * @brief The ERelationship_type enum
 */
enum ERelationship_type
{
  ERELATIONSHIP_TYPE_Abandonment,
  ERELATIONSHIP_TYPE_Breakup,
  ERELATIONSHIP_TYPE_Conflict,
  ERELATIONSHIP_TYPE_Dominance,
  ERELATIONSHIP_TYPE_Friendship,
  ERELATIONSHIP_TYPE_Lover,
  ERELATIONSHIP_TYPE_Marriage,
  ERELATIONSHIP_TYPE_Membership,
  ERELATIONSHIP_TYPE_Ownership,
  ERELATIONSHIP_TYPE_Parentage,
  ERELATIONSHIP_TYPE_Rivalry,
  ERELATIONSHIP_TYPE_Unrequited,
  ERELATIONSHIP_TYPE_Count
};

/**
 * @brief Lookup table mapping all enumerated event types to their appropriate string
 * representations.
 */
constexpr std::array<Enum_mapping<ERelationship_type>,
                     static_cast<size_t>(ERelationship_type::ERELATIONSHIP_TYPE_Count)> relationship_type_lookup = {
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Abandonment,  "abandonment"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Breakup,      "breakup"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Conflict,     "conflict"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Dominance,    "dominance"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Friendship,   "friendship"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Lover,        "lover"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Marriage,     "marriage"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Membership,   "membership"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Ownership,    "ownership"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Parentage,    "parentage"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Rivalry,      "rivalry"},
  Enum_mapping{ERelationship_type::ERELATIONSHIP_TYPE_Unrequited,   "unrequited"}
};

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
