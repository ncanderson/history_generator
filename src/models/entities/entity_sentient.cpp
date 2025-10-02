/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs
#include <string>

// JSON

// Application files
#include <models/entities/entity_sentient.h>
#include <models/data_definitions.h>
#include <modules/names.h>

///////////////////////////////////////////////////////////////////////

using sentient = his_gen::Entity_sentient;
using personality_attr = his_gen::Attribute_enums::EPersonality;
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
  initialize_max_events_by_type();
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

void sentient::Accept_event(Event_visitor& visitor)
{
  visitor.Visit_entity(*this);
}
///////////////////////////////////////////////////////////////////////

void sentient::initialize_max_events_by_type()
{
  // make each event tell you what it's default maximum is, then provide a virtual function in entity_base
  // that will allow any entity to override the defaults
  std::vector<his_gen::EEvent_type> entity_events = his_gen::Data_definitions::Get_entity_events(Get_entity_type());

  // Loop through all events
  for(const auto& event : entity_events)
  {
    // Start with the default derived from the base class
    uint16_t default_max_event = get_default_max_event_type();

    switch(event)
    {
      case his_gen::EEvent_type::EEVENT_TYPE_Seek_partner:
      {
        //Traits that push toward more lovers
        double expansive =
            0.6 * (m_personality.Get_entity_attribute_value(personality_attr::EPERSONALITY_Lustful) / 100.0) +
            0.4 * (m_personality.Get_entity_attribute_value(personality_attr::EPERSONALITY_Sociable) / 100.0) +
            0.3 * (m_personality.Get_entity_attribute_value(personality_attr::EPERSONALITY_Ambitious) / 100.0) +
            0.2 * (m_personality.Get_entity_attribute_value(personality_attr::EPERSONALITY_Extravagant) / 100.0) +
            0.2 * (m_personality.Get_entity_attribute_value(personality_attr::EPERSONALITY_Progressive) / 100.0);

        // Traits that push toward fewer lovers
        double restrictive =
            0.6 * (m_personality.Get_entity_attribute_value(personality_attr::EPERSONALITY_Chaste) / 100.0) +
            0.4 * (m_personality.Get_entity_attribute_value(personality_attr::EPERSONALITY_Conservative) / 100.0) +
            0.3 * (m_personality.Get_entity_attribute_value(personality_attr::EPERSONALITY_Avoidant) / 100.0) +
            0.2 * (m_personality.Get_entity_attribute_value(personality_attr::EPERSONALITY_Selfish) / 100.0);

        // Compute a balance: positive minus negative
        double drive = expansive - restrictive;

        // Shape it so small differences don’t swing too wildly; this gives ~ [-1, +2] adjustment range
        double adjustment = 3.0 * drive;
        double adjusted_value = static_cast<double>(default_max_event) + adjustment;

        // Set the max, including the adjustment, ensuring no negative values
        set_max_events(event, std::round(std::max(0.0, adjusted_value)));
        break;
      }
      case his_gen::EEvent_type::EEVENT_TYPE_Courtship:
      {
        set_max_events(event, 10);
        break;
      }
      case his_gen::EEvent_type::EEVENT_TYPE_Reproduce:
      {
        // TODO something here?
        set_max_events(event, 10);
        break;
      }

      default:
        // Unrecognized value
        throw std::invalid_argument("Event type not handled by entity, can't determine max count");
    }
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
