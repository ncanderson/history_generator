/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard
#include <modules/personality_attraction.h>

///////////////////////////////////////////////////////////////////////

his_gen::Personality_attraction::Personality_attraction()
    :
    Personality(),
    m_attraction_flexibility(derive_attraction_flexibility(Get_attributes()))
{

}

///////////////////////////////////////////////////////////////////////

int8_t his_gen::Personality_attraction::derive_attraction_flexibility(std::map<his_gen::Attribute, int8_t> attributes)
{
  /**
   * I think we really want to initialize all attributes in pairs, but then
   * save them separately. Because we want the attributes to make sense on a
   * spectrum, but be easy to understand when using. So if ATTRIBUTE_Cooperative_difficult
   * is 47, that means we have cooperative 47 and difficult 53.
   */
  int8_t attraction_flexibility = 0;

  int8_t cooperative_difficult = attributes[his_gen::Attribute::ATTRIBUTE_Cooperative_difficult];
  //int8_t flexible_extreme = attributes[his_gen::Attribute::ATTRIBUTE_Flexible_extremist];
  //int8_t jealous_compassionate = attributes[his_gen::Attribute::ATTRIBUTE_Jealous_compassionate];
  //int8_t truculent_amiable = attributes[his_gen::Attribute::ATTRIBUTE_Truculent_amiable];

  attraction_flexibility = cooperative_difficult;

  //"cooperative-difficult": 47,
  //"flexible-extremist": 82,
  //"jealous-compassionate": 25,
  //"truculent-amiable": 27,


  return attraction_flexibility;
}

///////////////////////////////////////////////////////////////////////

void his_gen::to_json(nlohmann::json& json,
                      const his_gen::Personality_attraction& personality_attraction)
{
  nlohmann::to_json(json, static_cast<his_gen::Personality>(personality_attraction));
  json.update(
  {
    {"attracted_to_can_sire", personality_attraction.Get_attracted_to_can_sire()},
    {"attracted_to_can_bear", personality_attraction.Get_attracted_to_can_sire()},
    {"attraction_flexibility", personality_attraction.Get_attraction_flexibility()}
  });
}

///////////////////////////////////////////////////////////////////////

void his_gen::from_json(const nlohmann::json& json,
                        his_gen::Personality_attraction& personality_attraction)
{

}

///////////////////////////////////////////////////////////////////////
// END OF FILE
