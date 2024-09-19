/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

#ifndef HISTORY_GENERATOR_ROOT_CONFIG_H
#define HISTORY_GENERATOR_ROOT_CONFIG_H

// Child Config
#include <utils/mythological_era_config.h>
#include <utils/historical_era_config.h>
#include <utils/end_times_era_config.h>
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
  /**
   * @brief Data access type
   * @details
   * | Value    | Description                                         |
   * |----------|-----------------------------------------------------|
   * | file     | Data will be saved and retrieved from a system file |
   * | postgres | PostgreSQL database                                 |
   */
  std::string Data_access_type;

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

  /**
   * @brief Validate_config
   * @param app_config
   */
  void Validate_config(const his_gen::History_generator_root_config& app_config) const;

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  /**
   * @brief Config specific to the mythological era
   */
  his_gen::Mythological_era_config m_myth_era_config;

  /**
   * @brief Config specific to the historical era
   */
  his_gen::Historical_era_config m_hist_era_config;

  /**
   * @brief Config specific to the end times era
   */
  his_gen::End_times_era_config m_end_times_era_config;
  // Implementation

}; // class History_generator_root_config
}  // namespace his_gen

#endif // HISTORY_GENERATOR_ROOT_CONFIG_H
