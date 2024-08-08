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
