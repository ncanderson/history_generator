#ifndef END_TIMES_ERA_CONFIG_H
#define END_TIMES_ERA_CONFIG_H

// JSON
#include <deps/json.hpp>

using json = nlohmann::json;

namespace his_gen
{
/**
 * @brief Config for the end times era
 */
class End_times_era_config
{
public:
  // Attributes
  /**
   * @brief Generator ticks to run in the end times era
   */
  uint32_t End_times_gen_ticks;

  /**
   * @brief Entities to generate per tick
   */
  uint32_t Max_entity_per_tick;

  /**
   * @brief If true, the world will face a major catastrophe and either emerge
   * relatively intact. If false, history will simply progress and the world's
   * history will fade to grey.
   */
  bool Violent_end_times;

  // Implementation
  /**
   * @brief Constructor
   */
  End_times_era_config();

  /**
   * @brief JSON constructor
   * @param from_json JSON object to instantiate the object from
   */
  End_times_era_config(json from_json);

  /**
   * @brief Destructor
   */
  virtual ~End_times_era_config(){};

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class End_times_era_config
}  // namespace his_gen

#endif // END_TIMES_ERA_CONFIG_H
