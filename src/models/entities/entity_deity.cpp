/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

// Standard libs

// JSON

// Application files
#include <models/entities/entity_deity.h>

///////////////////////////////////////////////////////////////////////

using deity = his_gen::Entity_deity;
using repro = his_gen::Attribute_enums::EReproduction;
REGISTER_POLYMORPHIC_TYPE(his_gen::Entity_base, his_gen::Entity_deity)

///////////////////////////////////////////////////////////////////////

deity::Entity_deity(const uint64_t current_tick)
  :
  his_gen::Entity_sentient(his_gen::EENTITY_TYPE_Deity, current_tick),
  m_test_attr(false)
{ }

///////////////////////////////////////////////////////////////////////

deity::Entity_deity(const std::string& name,
                    const std::string& title,
                    const uint64_t current_tick)
  :
  his_gen::Entity_sentient(name,
                           title,
                           his_gen::EENTITY_TYPE_Deity,
                           current_tick)
{ }

///////////////////////////////////////////////////////////////////////

void deity::Initialize()
{
  initialize_max_events_by_type();
  update_divine_physicality();
}

///////////////////////////////////////////////////////////////////////

void deity::update_divine_physicality()
{
  m_physicality.Set_repro_attribute_value(repro::EREPRODUCTION_Can_bear_young, his_gen::dice::Flip_a_coin());
  m_physicality.Set_repro_attribute_value(repro::EREPRODUCTION_Can_sire_young, his_gen::dice::Flip_a_coin());
  m_physicality.Set_repro_attribute_value(repro::EREPRODUCTION_Can_nurse_young, his_gen::dice::Flip_a_coin());

  m_physicality.Update_repro_dependent_attributes();
}

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Entity_deity& entity_deity)
{
  nlohmann::to_json(json, static_cast<const Entity_sentient&>(entity_deity));
  // Any additional attributes here

  //json.update(
  //{
  //  {"test_attr", entity_deity.Get_test_attr()},
  //});
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Entity_deity& entity_deity)
{

}

///////////////////////////////////////////////////////////////////////
