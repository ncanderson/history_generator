/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_TYPE_H
#define ENTITY_TYPE_H

// Standard libs

// JSON
#include <deps/json.hpp>

// Application files
#include <utils/history_generator_utils.h>
#include <defs/history_generator_defs.h>

namespace his_gen
{

/**
 * @brief Enumerates all entity types used in the historical simulation.
 */
enum EEntity_type
{
  //EENTITY_TYPE_Artifact,      ///< Powerful or significant object with historical weight.
  //EENTITY_TYPE_Beast,         ///< Natural, non-sapient creature.
  //EENTITY_TYPE_Clan_tribe,    ///< Kin-based or tribal social group.
  //EENTITY_TYPE_Culture,       ///< Shared customs, norms, and artistic expression.
  EENTITY_TYPE_Deity,         ///< Divine or supernatural being.
  //EENTITY_TYPE_Ethnicity,     ///< Culturally or racially distinct group.
  //EENTITY_TYPE_Event,         ///< A world-shaping historical moment; may reference other entities.
  //EENTITY_TYPE_Faction,       ///< Political or ideological group.
  //EENTITY_TYPE_House,         ///< Noble or dynastic lineage.
  //EENTITY_TYPE_Idea,          ///< Philosophy, ideology, or memetic construct.
  //EENTITY_TYPE_Institution,   ///< Academy, temple, court, guild, or bureaucracy.
  //EENTITY_TYPE_Language,      ///< Linguistic group.
  //EENTITY_TYPE_Legend,        ///< Story, myth, or persistent cultural narrative.
  //EENTITY_TYPE_Monster,       ///< Dangerous or supernatural creature.
  //EENTITY_TYPE_Nation,        ///< Sovereign political state.
  //EENTITY_TYPE_Order,         ///< Knightly, arcane, or secret order.
  //EENTITY_TYPE_Pantheon,      ///< Collection of related deities.
  //EENTITY_TYPE_Phenomenon,    ///< Magical, natural, or supernatural occurrence.
  //EENTITY_TYPE_Region,        ///< Geographic area (mountain, forest, desert, etc.).
  //EENTITY_TYPE_Religion,      ///< Organized faith or belief system.
  //EENTITY_TYPE_Ruin,          ///< Ancient or collapsed structure.
  EENTITY_TYPE_Sentient,      ///< A sapient individual (human, elf, etc.).
  EENTITY_TYPE_Count          ///< Sentinel
};

/**
 * @brief Lookup table mapping all enumerated entity types to their appropriate string
 * representations.
 */
constexpr std::array<Enum_mapping<EEntity_type>,
                     static_cast<size_t>(EEntity_type::EENTITY_TYPE_Count)> entity_type_lookup = {
  Enum_mapping{EEntity_type::EENTITY_TYPE_Deity,    "deity"},
  Enum_mapping{EEntity_type::EENTITY_TYPE_Sentient, "sentient"}
};

/**
 * @brief The type of entity
 */
class  Entity_type
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Default constructor, required for JSON serialization
   */
  Entity_type() = default;

  /**
   * @brief Constructor
   */
  Entity_type(const his_gen::EEntity_type& entity_type);

  /**
   * @brief Destructor
   */
  ~Entity_type() = default;

  /**
   * Getters and setters
   */
  std::string Get_name() const { return m_name; }
  his_gen::EEntity_type Get_entity_type() const { return m_entity_type; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Entity type name
   */
  std::string m_name;

  /**
   * @brief Enumerated entity type
   */
  his_gen::EEntity_type m_entity_type;

  // Implementation

}; // class Entity_type

/**
 * @brief to_json
 * @param json
 * @param entity_type
 */
void to_json(nlohmann::json& json,
             const his_gen::Entity_type& entity_type);

/**
 * @brief from_json
 * @param json
 * @param entity_type
 */
void from_json(const nlohmann::json& json,
               his_gen::Entity_type& entity_type);

}  // namespace his_gen

#endif // ENTITY_TYPE_H
