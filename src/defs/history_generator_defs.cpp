/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libraries
#include <stdexcept>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <cctype>

// Application files
#include <defs/history_generator_defs.h>
#include <utils/history_generator_utils.h>

///////////////////////////////////////////////////////////////////////

std::string his_gen::To_lowercase(const std::string& input_string)
{
  std::string result = input_string;
  std::transform(result.begin(), result.end(), result.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return result;
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_current_era(his_gen::Era current_era)
{
  switch(current_era)
  {
    case ERA_Unknown:   return "Unknown";       break;
    case ERA_Mythology: return "Mythology";     break;
    case ERA_History:   return "History";       break;
    case ERA_End_times: return "End Times";     break;
    case ERA_Terminate: return "Terminate";     break;
    default:            return "Era not found"; break;
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_current_stage(his_gen::Stage current_stage)
{
  switch(current_stage)
  {
    case STAGE_Init:      return "Init";            break;
    case STAGE_Run:       return "Run";             break;
    case STAGE_Terminate: return "Terminate";       break;
    default:              return "Stage not found"; break;
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_data_access_type(Data_access_type data_access_type)
{
  switch (data_access_type)
  {
    case DATA_ACCESS_TYPE_Unknown:  return "Unknown data access type";   break;
    case DATA_ACCESS_TYPE_File:     return "File";                       break;
    case DATA_ACCESS_TYPE_Postgres: return "PostgreSQL RMDS";            break;
    default:                        return "Data access type not found"; break;
  }
}

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_type his_gen::Get_data_access_type(std::string data_access_type)
{
  if(data_access_type == "file")
  {
    return DATA_ACCESS_TYPE_File;
  }
  else if(data_access_type == "postgres")
  {
    return DATA_ACCESS_TYPE_Postgres;
  }
  else
  {
    return DATA_ACCESS_TYPE_Unknown;
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_attribute_string(const his_gen::Attribute attribute)
{
  switch(attribute)
  {
    case ATTRIBUTE_Aggressive:    return "aggressive";
    case ATTRIBUTE_Passive:       return "passive";
    case ATTRIBUTE_Ambitious:     return "ambitious";
    case ATTRIBUTE_Content:       return "content";
    case ATTRIBUTE_Avoidant:      return "avoidant";
    case ATTRIBUTE_Sociable:      return "sociable";
    case ATTRIBUTE_Brave:         return "brave";
    case ATTRIBUTE_Cowardly:      return "cowardly";
    case ATTRIBUTE_Cooperative:   return "cooperative";
    case ATTRIBUTE_Difficult:     return "difficult";
    case ATTRIBUTE_Cruel:         return "cruel";
    case ATTRIBUTE_Kind:          return "kind";
    case ATTRIBUTE_Decisive:      return "decisive";
    case ATTRIBUTE_Indecisive:    return "indecisive";
    case ATTRIBUTE_Diligent:      return "diligent";
    case ATTRIBUTE_Lazy:          return "lazy";
    case ATTRIBUTE_Flexible:      return "flexible";
    case ATTRIBUTE_Extremist:     return "extremist";
    case ATTRIBUTE_Frank:         return "frank";
    case ATTRIBUTE_Evasive:       return "evasive";
    case ATTRIBUTE_Generous:      return "generous";
    case ATTRIBUTE_Selfish:       return "selfish";
    case ATTRIBUTE_Jealous:       return "jealous";
    case ATTRIBUTE_Compassionate: return "compassionate";
    case ATTRIBUTE_Placid:        return "placid";
    case ATTRIBUTE_Excitable:     return "excitable";
    case ATTRIBUTE_Thoughtful:    return "thoughtful";
    case ATTRIBUTE_Rash:          return "rash";
    case ATTRIBUTE_Thrifty:       return "thrifty";
    case ATTRIBUTE_Extravagant:   return "extravagant";
    case ATTRIBUTE_Argumentative: return "argumentative";
    case ATTRIBUTE_Amiable:       return "amiable";
    case ATTRIBUTE_Witty:         return "witty";
    case ATTRIBUTE_Humorless:     return "humorless";
    case ATTRIBUTE_Honest:        return "honest";
    case ATTRIBUTE_Deceitful:     return "deceitful";
    default:
      // Unrecognized value
      throw std::invalid_argument("Attribute not found");
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_entity_type_string(const his_gen::EEntity_type& entity_type)
{
  switch(entity_type)
  {
    case EENTITY_TYPE_Unknown:      return "unknown";
    case EENTITY_TYPE_Sentient:     return "sentient";
    case EENTITY_TYPE_Beast:        return "beast";
    case EENTITY_TYPE_Monster:      return "monster";
    case EENTITY_TYPE_Deity:        return "deity";
    case EENTITY_TYPE_Clan_tribe:   return "clan/tribe";
    case EENTITY_TYPE_Faction:      return "faction";
    case EENTITY_TYPE_Nation:       return "nation";
    case EENTITY_TYPE_Settlement:   return "settlement";
    case EENTITY_TYPE_Religion:     return "religion";
    case EENTITY_TYPE_Artifact:     return "artifact";
    case EENTITY_TYPE_Region:       return "region";
    case EENTITY_TYPE_Order:        return "order";
    case EENTITY_TYPE_Institution:  return "institution";
    case EENTITY_TYPE_House:        return "house";
    case EENTITY_TYPE_Ethnicity:    return "ethnicity";
    case EENTITY_TYPE_Culture:      return "culture";
    case EENTITY_TYPE_Language:     return "language";
    case EENTITY_TYPE_Ruin:         return "ruin";
    case EENTITY_TYPE_Phenomenon:   return "phenomenon";
    case EENTITY_TYPE_Pantheon:     return "pantheon";
    case EENTITY_TYPE_Idea:         return "idea";
    case EENTITY_TYPE_Legend:       return "legend";
    case EENTITY_TYPE_Event:        return "event";
    default:
      throw std::invalid_argument("Entity type not found");
  }
}


///////////////////////////////////////////////////////////////////////

his_gen::EEntity_type his_gen::Get_entity_type(const std::string& entity_type)
{
  static const std::unordered_map<std::string, EEntity_type> entity_type_map =
  {
    {"unknown",       EENTITY_TYPE_Unknown},
    {"sentient",      EENTITY_TYPE_Sentient},
    {"beast",         EENTITY_TYPE_Beast},
    {"monster",       EENTITY_TYPE_Monster},
    {"deity",         EENTITY_TYPE_Deity},
    {"clan/tribe",    EENTITY_TYPE_Clan_tribe},
    {"faction",       EENTITY_TYPE_Faction},
    {"nation",        EENTITY_TYPE_Nation},
    {"settlement",    EENTITY_TYPE_Settlement},
    {"religion",      EENTITY_TYPE_Religion},
    {"artifact",      EENTITY_TYPE_Artifact},
    {"region",        EENTITY_TYPE_Region},
    {"order",         EENTITY_TYPE_Order},
    {"institution",   EENTITY_TYPE_Institution},
    {"house",         EENTITY_TYPE_House},
    {"ethnicity",     EENTITY_TYPE_Ethnicity},
    {"culture",       EENTITY_TYPE_Culture},
    {"language",      EENTITY_TYPE_Language},
    {"ruin",          EENTITY_TYPE_Ruin},
    {"phenomenon",    EENTITY_TYPE_Phenomenon},
    {"pantheon",      EENTITY_TYPE_Pantheon},
    {"idea",          EENTITY_TYPE_Idea},
    {"legend",        EENTITY_TYPE_Legend},
    {"event",         EENTITY_TYPE_Event}
  };

  const std::string lc_entity_type = his_gen::To_lowercase(entity_type);

  auto it = entity_type_map.find(lc_entity_type);
  if (it != entity_type_map.end())
  {
    return it->second;
  }
  else
  {
    his_gen::Print_to_cout(lc_entity_type);
    throw std::invalid_argument("Can't find entity type from string");
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_relationship_type_string(const ERelationship_type& relationship_type)
{
  switch(relationship_type)
  {
    case ERELATIONSHIP_TYPE_Conflict:   return "conflict";
    case ERELATIONSHIP_TYPE_Dominance:  return "dominance";
    case ERELATIONSHIP_TYPE_Friendship: return "friendship";
    case ERELATIONSHIP_TYPE_Lover:      return "lover";
    case ERELATIONSHIP_TYPE_Marriage:   return "marriage";
    case ERELATIONSHIP_TYPE_Membership: return "membership";
    case ERELATIONSHIP_TYPE_Ownership:  return "ownership";
    case ERELATIONSHIP_TYPE_Parentage:  return "parentage";
    default:
      // Unrecognized value
      throw std::invalid_argument("Relationship type not found");
  }
}

///////////////////////////////////////////////////////////////////////

his_gen::ERelationship_type his_gen::Get_relationship_type(const std::string& relationship_type)
{
  static const std::unordered_map<std::string,
                                  ERelationship_type> relationship_type_map =
  {
    {"marriage",   ERELATIONSHIP_TYPE_Marriage},
    {"lover",      ERELATIONSHIP_TYPE_Lover},
    {"conflict",   ERELATIONSHIP_TYPE_Conflict},
    {"parentage",  ERELATIONSHIP_TYPE_Parentage},
    {"dominance",  ERELATIONSHIP_TYPE_Dominance},
    {"friendship", ERELATIONSHIP_TYPE_Friendship},
    {"ownership",  ERELATIONSHIP_TYPE_Ownership},
    {"membership", ERELATIONSHIP_TYPE_Membership}
  };

  const std::string lc_relationship_type = his_gen::To_lowercase(relationship_type);

  auto it = relationship_type_map.find(lc_relationship_type);
  if (it != relationship_type_map.end())
  {
    return it->second;
  }
  else
  {
    his_gen::Print_to_cout(lc_relationship_type);
    throw std::invalid_argument("Can't find relationship type from string");
  }
}

///////////////////////////////////////////////////////////////////////

std::string his_gen::Get_event_type_string(const EEvent_type event_type)
{
  switch (event_type)
  {
    case EEVENT_TYPE_Absorbed_group:      return "absorbed_group";
    case EEVENT_TYPE_Altered_identity:    return "altered_identity";
    case EEVENT_TYPE_Assassinated_leader: return "assassinated_leader";
    case EEVENT_TYPE_Attacked_entity:     return "attacked_entity";
    case EEVENT_TYPE_Bred:                return "bred";
    case EEVENT_TYPE_Changed_leadership:  return "changed_leadership";
    case EEVENT_TYPE_Initiated_conflict:  return "initiated_conflict";
    case EEVENT_TYPE_Demanded_sacrifice:  return "demanded_sacrifice";
    case EEVENT_TYPE_Died:                return "died";
    case EEVENT_TYPE_Emerged:             return "emerged";
    case EEVENT_TYPE_Enacted_policy:      return "enacted_policy";
    case EEVENT_TYPE_Established_lair:    return "established_lair";
    case EEVENT_TYPE_Formed_alliance:     return "formed_alliance";
    case EEVENT_TYPE_Gained_follower:     return "gained_follower";
    case EEVENT_TYPE_Initiated_revolt:    return "initiated_revolt";
    case EEVENT_TYPE_Intervened_in_world: return "intervened_in_world";
    case EEVENT_TYPE_Joined_group:        return "joined_group";
    case EEVENT_TYPE_Killed_entity:       return "killed_entity";
    case EEVENT_TYPE_Lost_follower:       return "lost_follower";
    case EEVENT_TYPE_Married:             return "married";
    case EEVENT_TYPE_Merged_into_group:   return "merged_into_group";
    case EEVENT_TYPE_Moved_location:      return "moved_location";
    case EEVENT_TYPE_Moved_territory:     return "moved_territory";
    case EEVENT_TYPE_Opposed_policy:      return "opposed_policy";
    case EEVENT_TYPE_Performed_ritual:    return "performed_ritual";
    case EEVENT_TYPE_Signed_treaty:       return "signed_treaty";
    case EEVENT_TYPE_Split_from_group:    return "split_from_group";
    case EEVENT_TYPE_Spread_fear:         return "spread_fear";
    case EEVENT_TYPE_Spread_influence:    return "spread_influence";
    case EEVENT_TYPE_Subverted_rival:     return "subverted_rival";
    case EEVENT_TYPE_Was_captured:        return "was_captured";
    case EEVENT_TYPE_Was_hunted:          return "was_hunted";
    case EEVENT_TYPE_Was_subdued:         return "was_subdued";
    default:
      throw std::invalid_argument("Event type not found");
  }
}

///////////////////////////////////////////////////////////////////////

his_gen::EEvent_type his_gen::Get_event_type(const std::string& event_type)
{
  static const std::unordered_map<std::string, EEvent_type> event_type_map = {
      {"absorbed_group",      EEVENT_TYPE_Absorbed_group},
      {"altered_identity",    EEVENT_TYPE_Altered_identity},
      {"assassinated_leader", EEVENT_TYPE_Assassinated_leader},
      {"attacked_entity",     EEVENT_TYPE_Attacked_entity},
      {"bred",                EEVENT_TYPE_Bred},
      {"changed_leadership",  EEVENT_TYPE_Changed_leadership},
      {"initiated_conflict",  EEVENT_TYPE_Initiated_conflict},
      {"demanded_sacrifice",  EEVENT_TYPE_Demanded_sacrifice},
      {"died",                EEVENT_TYPE_Died},
      {"emerged",             EEVENT_TYPE_Emerged},
      {"enacted_policy",      EEVENT_TYPE_Enacted_policy},
      {"established_lair",    EEVENT_TYPE_Established_lair},
      {"formed_alliance",     EEVENT_TYPE_Formed_alliance},
      {"gained_follower",     EEVENT_TYPE_Gained_follower},
      {"initiated_revolt",    EEVENT_TYPE_Initiated_revolt},
      {"intervened_in_world", EEVENT_TYPE_Intervened_in_world},
      {"joined_group",        EEVENT_TYPE_Joined_group},
      {"killed_entity",       EEVENT_TYPE_Killed_entity},
      {"lost_follower",       EEVENT_TYPE_Lost_follower},
      {"married",             EEVENT_TYPE_Married},
      {"merged_into_group",   EEVENT_TYPE_Merged_into_group},
      {"moved_location",      EEVENT_TYPE_Moved_location},
      {"moved_territory",     EEVENT_TYPE_Moved_territory},
      {"opposed_policy",      EEVENT_TYPE_Opposed_policy},
      {"performed_ritual",    EEVENT_TYPE_Performed_ritual},
      {"signed_treaty",       EEVENT_TYPE_Signed_treaty},
      {"split_from_group",    EEVENT_TYPE_Split_from_group},
      {"spread_fear",         EEVENT_TYPE_Spread_fear},
      {"spread_influence",    EEVENT_TYPE_Spread_influence},
      {"subverted_rival",     EEVENT_TYPE_Subverted_rival},
      {"was_captured",        EEVENT_TYPE_Was_captured},
      {"was_hunted",          EEVENT_TYPE_Was_hunted},
      {"was_subdued",         EEVENT_TYPE_Was_subdued}
  };

  const std::string lc_event_type = his_gen::To_lowercase(event_type);

  auto it = event_type_map.find(lc_event_type);
  if (it != event_type_map.end())
  {
    return it->second;
  }
  else
  {
    his_gen::Print_to_cout(lc_event_type);
    throw std::invalid_argument("Can't find event type from string");
  }
}
