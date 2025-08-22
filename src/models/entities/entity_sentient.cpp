/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs
#include <string>

// JSON

// Application files
#include <defs/json_helper_defs.h>
#include <models/entities/entity_sentient.h>
#include <modules/names.h>

///////////////////////////////////////////////////////////////////////

using sentient = his_gen::Entity_sentient;
REGISTER_POLYMORPHIC_TYPE(his_gen::Entity_base, his_gen::Entity_sentient)

///////////////////////////////////////////////////////////////////////

sentient::Entity_sentient(const EEntity_type entity_type,
                          const uint64_t current_tick)
  :
  Entity_base(his_gen::Names::Get_one_name(),
              entity_type,
              current_tick,
              his_gen::Names::Get_one_title()),
  m_personality(),
  m_personality_attraction(m_personality.Get_attributes()),
  m_personality_attraction_thresh(derive_attraction_thresh(m_personality_attraction.Get_personality_attraction_flexibility())),
  m_physicality(),
  m_physicality_attraction(m_personality),
  m_physicality_attraction_thresh(derive_attraction_thresh(m_physicality_attraction.Get_physical_attraction_flexibility())),
  m_attraction_risk_appetite(m_personality_attraction.Get_risk_appetite())
{ }

///////////////////////////////////////////////////////////////////////

sentient::Entity_sentient(const std::string& name,
                          const std::string& title,
                          const EEntity_type entity_type,
                          const uint64_t current_tick)
  :
  Entity_base(name, entity_type, current_tick, title),
  m_personality(),
  m_personality_attraction(m_personality.Get_attributes()),
  m_personality_attraction_thresh(derive_attraction_thresh(m_personality_attraction.Get_personality_attraction_flexibility())),
  m_physicality(),
  m_physicality_attraction(m_personality),
  m_physicality_attraction_thresh(derive_attraction_thresh(m_physicality_attraction.Get_physical_attraction_flexibility())),
  m_attraction_risk_appetite(m_personality_attraction.Get_risk_appetite())
{ }

///////////////////////////////////////////////////////////////////////

void sentient::Initialize()
{
  // NOOP
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
  return compare_attributes<his_gen::Personality>(Get_personality(), other->Get_personality()) &&
         compare_attributes<his_gen::Physicality>(Get_physicality(), other->Get_physicality());
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

double sentient::derive_attraction_thresh(uint8_t entity_flexibility)
{
  // TODO: Take this 50, hard code it in defs, and then derive the flexiblity divisor from there
  // TODO: put this 50.0 somewhere that makes more sense. It's tied to the flexibiliy divisor:
  // divisor = X where MAX_SCORE / X = max flexibility
  // Scale the attraction flexibility to a 0 - 1 range, use the max flexibility
  // Scale the flexibility based on max flexibilty
  double scaled_flexibility = (entity_flexibility) / 50.0;
  // Return the threshold, based on the scale flexibility
  return 1.0 - scaled_flexibility;
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
    {"physical_attraction", entity_sentient.Get_physicality_attraction()}
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
