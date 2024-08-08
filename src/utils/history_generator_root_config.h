#ifndef HISTORY_GENERATOR_ROOT_CONFIG_H
#define HISTORY_GENERATOR_ROOT_CONFIG_H

#include <stdint.h>
// JSON
#include <deps/json.hpp>

using json = nlohmann::json;

namespace his_gen
{
/**
 * @brief Application root config
 * @details This class will form the core of the applications's config. It will
 * contain objects for each era's generator config, and be used as the primary
 * vehicle for propagating config to classes that need it.
 */
class History_generator_root_config
{
public:
  // Attributes
  uint32_t Myth_gen_ticks;

  // Implementation
  /**
   * @brief Constructor
   */
  History_generator_root_config();

  /**
   * @brief JSON constructor
   * @param from_json JSON object to instantiate the object from
   */
  History_generator_root_config(json from_json);

  /**
   * @brief Destructor
   */
  virtual ~History_generator_root_config(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class History_generator_root_config
}  // namespace his_gen

#endif // HISTORY_GENERATOR_ROOT_CONFIG_H
