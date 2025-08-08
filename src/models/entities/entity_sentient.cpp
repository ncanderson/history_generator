/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <models/entities/entity_sentient.h>

// Defs and Utils
#include <defs/json_helper_defs.h>
#include <utils/dice_rolls.h>

using sentient = his_gen::Entity_sentient;

///////////////////////////////////////////////////////////////////////

sentient::Entity_sentient(std::string name,
                          std::string title,
                          EEntity_type entity_type)
  :
  Entity_base(name, entity_type, title),
  m_personality(),
  m_personality_attraction(m_personality.Get_attributes()),
  m_personality_attraction_thresh(derive_personality_attraction_thresh()),
  m_physicality(),
  m_physicality_attraction(m_personality),
  m_physicality_attraction_thresh(derive_physicality_attraction_thresh()),
  m_lovers(),
  m_spouses()
{
  // TODO Don't do this for every entity, move it somewhere so we do it once per class
  // Register the derived class with the JSON serializer
  Polymorphic_serializer<his_gen::Entity_base>::register_types<his_gen::Entity_base,
                                                               his_gen::Entity_sentient>();
}

///////////////////////////////////////////////////////////////////////

bool sentient::Is_attracted(std::shared_ptr<Entity_base> other_entity)
{
  // Downcast to derived class from the base class pointer
  std::shared_ptr<his_gen::Entity_sentient> other = std::dynamic_pointer_cast<his_gen::Entity_sentient>(other_entity);

  // Check reproduction attraction first, and ensure we're not comparing an entity to itself
  if(other == shared_from_this() || !repro_attraction(other))
  {
    return false;
  }
  return compare_personalities(other) && compare_physicalities(other);
}

///////////////////////////////////////////////////////////////////////

bool sentient::Is_attracted(std::shared_ptr<Entity_base> other_entity,
                            std::vector<std::shared_ptr<Entity_base>> attracted_to)
{
  if(Is_attracted(other_entity))
  {
    // Downcast to derived class from the base class pointer
    std::shared_ptr<his_gen::Entity_sentient> other = std::dynamic_pointer_cast<his_gen::Entity_sentient>(other_entity);
    attracted_to.push_back(other);
    return true;
  }
  else
  {
    return false;
  }
}

///////////////////////////////////////////////////////////////////////

bool sentient::repro_attraction(std::shared_ptr<his_gen::Entity_sentient> other_entity)
{
  // Attributes of self
  bool attracted_to_bear = m_physicality_attraction.Attracted_to_bearing();
  bool attracted_to_sire = m_physicality_attraction.Attracted_to_siring();

  // Attributes of other
  bool other_can_bear = other_entity->Get_physicality().Can_bear_young();
  bool other_can_sire = other_entity->Get_physicality().Can_sire_young();

  return (attracted_to_bear && other_can_bear) || (attracted_to_sire && other_can_sire);
}

///////////////////////////////////////////////////////////////////////

uint8_t sentient::derive_personality_attraction_thresh()
{
  // Get the flexibility. This is inverted, so that higher flexibility means a lower coefficient
  double flexibility_coefficient = (100 - m_personality_attraction.Get_personality_attraction_flexibility()) / 100.0;
  // Get the attr count
  int8_t attr_count = m_personality.Get_attributes().size();
  // Return the percentage of the total attributes that need to be compatible
  return round(attr_count * flexibility_coefficient);
}

///////////////////////////////////////////////////////////////////////

bool sentient::compare_personalities(std::shared_ptr<his_gen::Entity_sentient> other_entity)
{
  uint8_t compatible_attributes = 0;
  for(auto& it : m_personality_attraction.Get_attributes())
  {
    if(personality_attributes_compatible(other_entity, it.first))
    {
      compatible_attributes++;
    }
    // If there are enough compatible attributes, return true
    if(compatible_attributes >= m_personality_attraction_thresh)
    {
      return true;
    }
  }
  // If we made it the end of the attributes and haven't met the threshold, there isn't attraction
  return false;
}

///////////////////////////////////////////////////////////////////////

bool sentient::personality_attributes_compatible(std::shared_ptr<his_gen::Entity_sentient> other_entity,
                                                 Personality::Personality_attribute pers_attr_to_compare)
{
  uint8_t self_attr = m_personality_attraction.Get_personality_attribute_value(pers_attr_to_compare);
  uint8_t other_attr = other_entity->Get_personality().Get_personality_attribute_value(pers_attr_to_compare);
  return std::abs(self_attr - other_attr) >= m_personality_attraction.Get_personality_attraction_flexibility();
}

///////////////////////////////////////////////////////////////////////

uint8_t sentient::derive_physicality_attraction_thresh()
{
  // Get the flexibility. This is inverted, so that higher flexibility means a lower coefficient
  double flexibility_coefficient = (100 - m_physicality_attraction.Get_physical_attraction_flexibility()) / 100.0;
  // Get the attr count
  int8_t attr_count = m_physicality.Get_physical_attributes().size();
  // Return the percentage of the total attributes that need to be compatible
  return round(attr_count * flexibility_coefficient);
}

///////////////////////////////////////////////////////////////////////

bool sentient::compare_physicalities(std::shared_ptr<his_gen::Entity_sentient> other_entity)
{
  uint8_t compatible_attributes = 0;
  for(auto& it : m_physicality_attraction.Get_physical_attributes())
  {
    if(physicality_attributes_compatible(other_entity, it.first))
    {
      compatible_attributes++;
    }
    // If there are enough compatible attributes, return true
    if(compatible_attributes >= m_physicality_attraction_thresh)
    {
      return true;
    }
  }
  // If we made it the end of the attributes and haven't met the threshold, there isn't attraction
  return false;
}

///////////////////////////////////////////////////////////////////////

bool sentient::physicality_attributes_compatible(std::shared_ptr<his_gen::Entity_sentient> other_entity,
                                                 Physicality::Physical_attribute phys_attr_to_compare)
{
  if(phys_attr_to_compare == Physicality::Physical_attribute::PHYSICAL_ATTRIBUTE_Can_sire_young ||
      phys_attr_to_compare == Physicality::Physical_attribute::PHYSICAL_ATTRIBUTE_Can_sire_young ||
      phys_attr_to_compare == Physicality::Physical_attribute::PHYSICAL_ATTRIBUTE_Can_sire_young)
  {
    // TODO: Handle this differently. I didn't really think about this aspect. We're checking repro
    // attraction via different methods, so why include them in the main enum at all? Should consider
    // a separate enum, or a struct within the physicality class, or something else since actually
    // the way we are comparing attrs is totally different so having them in the same place may not make any sense.
    return false;
  }
  uint8_t self_attr = m_physicality_attraction.Get_physical_attribute_value<uint8_t>(phys_attr_to_compare);
  uint8_t other_attr = other_entity->Get_physicality().Get_physical_attribute_value<uint8_t>(phys_attr_to_compare);
  return std::abs(self_attr - other_attr) >= m_physicality_attraction.Get_physical_attraction_flexibility();
}

///////////////////////////////////////////////////////////////////////
// JSON Helpers

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_sentient& entity_sentient)
{
  nlohmann::to_json(json, static_cast<const Entity_base&>(entity_sentient));
  json.update(
  {
    {"personality", entity_sentient.Get_personality()},
    {"attraction", entity_sentient.Get_personality_attraction()},
    {"physicality", entity_sentient.Get_physicality()},
    {"physical_attraction", entity_sentient.Get_physicality_attraction()},
    {"lovers", entity_sentient.Get_lovers()},
    {"spouses", entity_sentient.Get_spouses()}
  });
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_sentient& entity_sentient)
{
  entity_sentient.Set_name(json.at("name"));
  entity_sentient.Set_title(json.at("title"));
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
