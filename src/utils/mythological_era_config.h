/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef MYTHOLOGICAL_ERA_CONFIG_H
#define MYTHOLOGICAL_ERA_CONFIG_H

// JSON
#include <deps/json.hpp>

using json = nlohmann::json;

namespace his_gen
{
/**
 * @brief Config for the mythological era
 */
class Mythological_era_config
{
public:
  // Attributes
  /**
   * @brief Generator ticks to run in the mythological era
   */
  uint32_t Myth_gen_ticks;

  /**
   * @brief Entities to generate per tick
   */
  uint32_t Max_entity_per_tick;

  /**
   * @brief If true, there will be a 50/50 chance for both 'can sire' and 'can
   * bear', meaning some gods will be able to do both or neither.
   */
  bool Full_random_reproduction{false};

  // Implementation
  /**
   * @brief Constructor
   */
  Mythological_era_config();

  /**
   * @brief JSON constructor
   * @param from_json JSON object to instantiate the object from
   */
  Mythological_era_config(json from_json);

  /**
   * @brief Destructor
   */
  virtual ~Mythological_era_config(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Mythological_era_config
}  // namespace his_gen

#endif // MYTHOLOGICAL_ERA_CONFIG_H
