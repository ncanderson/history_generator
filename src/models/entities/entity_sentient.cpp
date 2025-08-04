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
                          EEntity_type entity_type,
                          bool full_random_reproduction)
  :
  Entity_base(name, entity_type, title),
  m_personality(),
  m_personality_attraction(m_personality.Get_attributes()),
  m_can_sire_young(),
  m_can_bear_young(),
  m_lovers(),
  m_spouses()
{
  // TODO Don't do this for every entity, move it somewhere so we do it once per class
  // Register the derived class with the JSON serializer
  Polymorphic_serializer<his_gen::Entity_base>::register_types<his_gen::Entity_base,
                                                               his_gen::Entity_sentient>();

  // Initialize reproductive ability
  if(full_random_reproduction)
  {
    m_can_sire_young = his_gen::Flip_a_coin();
    m_can_bear_young = his_gen::Flip_a_coin();
  }
  else
  {
    // TODO: This doesn't account for infertility when reproduction ability
    // isn't fully randomized
    m_can_sire_young = his_gen::Flip_a_coin();
    m_can_bear_young = !m_can_sire_young;
  }
}

///////////////////////////////////////////////////////////////////////

bool sentient::Is_attracted(std::shared_ptr<Entity_base> other_entity)
{
  // Downcast to derived class from the base class pointer
  std::shared_ptr<his_gen::Entity_sentient> other = std::dynamic_pointer_cast<his_gen::Entity_sentient>(other_entity);

  // Check reproduction attraction first, before looping through attributes and
  // ensure we're not comparing an entity to itself
  if(other == shared_from_this() || !repro_attraction(other))
  {
    return false;
  }
  else
  {
    // Still here? Check attributes.
    for(auto& it : m_personality_attraction.Get_attributes())
    {
      // Subtract the argued entity attribute from the attraction attribute,
      // take the absolute value, and compare it to the attraction flexibility.
      // This will return false if any compared attribute doesn't meet the
      // flexibility requirements.
      if(std::abs(it.second - other->Get_personality().Get_attributes()[it.first]) >=
          m_personality_attraction.Get_attraction_flexibility())
      {
        return false;
      }
      else
      {
        return true;
      }
    }
    // If we haven't returned by now, there isn't any attraction
    return false;
  }
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
  bool attraction_to_bear = m_personality_attraction.Get_attracted_to_can_bear();
  bool attraction_to_sire = m_personality_attraction.Get_attracted_to_can_sire();

  // Attributes of other
  bool other_can_bear = other_entity->Get_can_bear();
  bool other_can_sire = other_entity->Get_can_sire();

  if((attraction_to_bear && other_can_bear) || (attraction_to_sire && other_can_sire))
  {
    return true;
  }
  else
  {
    return false;
  }
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
    {"can_sire_young", entity_sentient.Get_can_sire()},
    {"can_bear_young", entity_sentient.Get_can_bear()},
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
