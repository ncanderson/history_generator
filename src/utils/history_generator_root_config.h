#ifndef HISTORY_GENERATOR_CONFIG_H
#define HISTORY_GENERATOR_CONFIG_H

#include <stdint.h>
// JSON
#include <deps/json.hpp>

using json = nlohmann::json;

namespace his_gen
{
/**
 * @brief Application config
 * @details
 */
class History_generator_config
{
public:
  // Attributes
  uint32_t Myth_gen_ticks;

  // Implementation
  /**
   * @brief Constructor
   */
  History_generator_config();

  /**
   * @brief JSON constructor
   * @param from_json JSON object to instantiate the object from
   */
  History_generator_config(json from_json);

  /**
   * @brief Destructor
   */
  virtual ~History_generator_config(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class History_generator_config_base
}  // namespace his_gen

#endif // HISTORY_GENERATOR_CONFIG_H
