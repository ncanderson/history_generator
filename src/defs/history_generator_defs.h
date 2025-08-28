/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORY_GENERATOR_DEFS_H
#define HISTORY_GENERATOR_DEFS_H

// Standard libraries
#include <string>

namespace his_gen
{

/**
 * @brief Max value to use when generating attributes
 */
static const uint8_t ATTRIBUTE_MAX = 100;

/**
 * @brief Double version of the attribute max, used for dividing
 * when a double is necessary.
 */
static const double ATTRIBUTE_MAX_DOUBLE = static_cast<double>(ATTRIBUTE_MAX);

/**
 * @brief Make a string lowercase
 * @param input_string
 * @return The converted string
 */
std::string To_lowercase(const std::string& input_string);

/**
 * @brief The Era enum
 * @details Track the current position within the overall generation
 */
enum Era
{
  ERA_Unknown   = -1, ///< Unknown/init state
  ERA_Mythology = 0,  ///< Age of mythology, especially gods
  ERA_History   = 1,  ///< Age of history, mostly humans
  ERA_End_times = 2,  ///< Any wrap-up or post-generation tasks
  ERA_Terminate = 3   ///< End generation, terminate application
};

/**
 * @brief Get the current era
 * @param current_era The current era
 * @return The string representation of the current era
 */
std::string Get_current_era(Era current_era);

/**
 * @brief The Stage enum
 * @details Track steps taken within each generation era
 */
enum Stage
{
  STAGE_Init,      ///< Initialize and setup
  STAGE_Run,       ///< Execution of era generation
  STAGE_Terminate  ///< Wrap-up and transition
};

/**
 * @brief Get the current stage
 * @param current_stage The current stage
 * @return The string representation of the current stage
 */
std::string Get_current_stage(Stage current_stage);

/**
 * @brief The Data_access_type enum
 * @details Determine the type of data source we'll be accessing
 */
enum Data_access_type
{
  DATA_ACCESS_TYPE_Unknown,  ///< Unknown data access type
  DATA_ACCESS_TYPE_File,     ///< File
  DATA_ACCESS_TYPE_Postgres  ///< PostgreSQL database
};

/**
 * @brief Get the current data access type
 * @param data_access_type The current data access type
 * @return The string representation of the access type
 */
std::string Get_data_access_type(Data_access_type data_access_type);

/**
 * @brief Get enumerated data access type from a string
 * @param data_access_type The string representation of the access type
 * @return String access type enumeration
 */
his_gen::Data_access_type Get_data_access_type(std::string data_access_type);

/**
 * @brief Struct to hold the details necessary to create a file data connection
 */
struct DAL_file_params
{
  /**
   * @brief Data file name
   */
  std::string filename;

  /**
   * @brief Path to data file to load
   */
  std::string file_path;
}; // struct DAL_file_details

/**
 * @brief Struct to hold the details necessary to create a PostgreSQL data
 * connection
 */
struct DAL_PG_params
{
  /**
   * @brief Database name
   */
  std::string db_name;

}; // struct DAL_PG_details

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
  EENTITY_TYPE_Sentient       ///< A sapient individual (human, elf, etc.).
  //EENTITY_TYPE_Settlement     ///< Village, city, fortress, or other habitation.
};


/**
 * @brief Get the entity type string from its enumerated value
 * @param entity_type Enumerated entity type
 * @return The string representation of the enumeration
 */
std::string Get_entity_type_string(const EEntity_type& entity_type);

/**
 * @brief Get the entity type string from its enumerated value
 * @param entity_type String representation of the entity type
 * @return The string representation of the enumeration
 */
EEntity_type Get_entity_type(const std::string& entity_type);

/**
 * @brief The ERelationship_type enum
 */
enum ERelationship_type
{
  ERELATIONSHIP_TYPE_Conflict,    ///< Conflict
  ERELATIONSHIP_TYPE_Dominance,   ///< Dominance
  ERELATIONSHIP_TYPE_Friendship,  ///< Friendship
  ERELATIONSHIP_TYPE_Lover,       ///< Lover
  ERELATIONSHIP_TYPE_Marriage,    ///< Marriage
  ERELATIONSHIP_TYPE_Membership,  ///< Membership, like to an organization or nation
  ERELATIONSHIP_TYPE_Ownership,   ///< Ownership over something
  ERELATIONSHIP_TYPE_Parentage    ///< Parentage
};

/**
 * @brief Get the relationship type string from its enumerated value
 * @param relationship_type Enumerated relationship type
 * @return The string representation of the enumeration
 */
std::string Get_relationship_type_string(const ERelationship_type& relationship_type);

/**
 * @brief Get the relationship type string from its enumerated value
 * @param relationship_type String representation of the relationship type
 * @return The string representation of the enumeration
 */
ERelationship_type Get_relationship_type(const std::string& relationship_type);

/**
 * @brief Enumerates all general event types used in the historical simulation.
 */
enum EEvent_type
{
  EEVENT_TYPE_Courtship,    ///< Further a lover relationship, determine where it goes
  EEVENT_TYPE_Reproduce,    ///< Create a new entity
  EEVENT_TYPE_Seek_partner  ///< Seek a partner, romatic or otherwise
};

/**
 * @brief Get the string representation of an EEvent_type.
 * @param event_type The event type enum value.
 * @return Lowercase string form (e.g. "died", "formed_alliance").
 */
std::string Get_event_type_string(const EEvent_type& event_type);

/**
 * @brief Convert a string to its corresponding EEvent_type enum value.
 * @param event_type The string to convert (case-insensitive).
 * @return Matching enum value.
 * @throws std::invalid_argument Thrown if no match is found.
 */
EEvent_type Get_event_type(const std::string& event_type);

}  // namespace his_gen

#endif // HISTORY_GENERATOR_DEFS_H
