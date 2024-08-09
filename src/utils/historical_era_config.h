#ifndef HISTORICAL_ERA_CONFIG_H
#define HISTORICAL_ERA_CONFIG_H

// JSON
#include <deps/json.hpp>

using json = nlohmann::json;

namespace his_gen
{
/**
 * @brief Config for the historical era
 */
class Historical_era_config
{
public:
  // Attributes
  /**
   * @brief Generator ticks to run in the historical era
   */
  uint32_t Hist_gen_ticks;

  /**
   * @brief Entities to generate per tick
   */
  uint32_t Max_entity_per_tick;

  // Implementation
  /**
   * @brief Constructor
   */
  Historical_era_config();

  /**
   * @brief JSON constructor
   * @param from_json JSON object to instantiate the object from
   */
  Historical_era_config(json from_json);

  /**
   * @brief Destructor
   */
  virtual ~Historical_era_config(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Historical_era_config
}  // namespace his_gen

#endif // HISTORICAL_ERA_CONFIG_H
