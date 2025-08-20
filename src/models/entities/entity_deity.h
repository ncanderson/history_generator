/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_DEITY_H
#define ENTITY_DEITY_H

// Standard libs

// JSON

// Application files
#include <models/entities/entity_sentient.h>

namespace his_gen
{
/**
 * @brief A generated entity
 */
class Entity_deity : public Entity_sentient
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor allowing the utilization of static name/title retrieval
   * @param entity_type The type of entity to instantiate.
   * @param current_tick The current generation tick
   */
  Entity_deity(const uint64_t current_tick);

  /**
   * @brief Overloaded constructor if an externally-specified name
   * and title are desired
   * @param name
   * @param title
   * @param entity_type
   * @param current_tick
   */
  Entity_deity(const std::string& name,
               const std::string& title,
               const uint64_t current_tick);

  /**
   * @brief Destructor
   */
  ~Entity_deity(){};

  /**
   * @brief Initialize this class's attributes
   */
  //void Initialize() override;

  /**
   * Getters and Setters
   */
  bool Get_test_attr() const { return m_test_attr; }

protected:
  // Attributes

  // Implementation

private:
  // Attributes
  /**
   * @brief Test for JSON serialization
   */
  bool m_test_attr;

  // Implementation
  /**
   * @brief Override the reproductive attributes of this deity
   */
  void update_divine_physicality();

}; // class Entity_deity

/**
 * @brief to_json
 * @param json
 * @param entity_deity
 */
void to_json(nlohmann::json& json,
             const his_gen::Entity_deity& entity_deity);

/**
 * @brief from_json
 * @param json
 * @param entity_deity
 */
void from_json(const nlohmann::json& json,
               his_gen::Entity_deity& entity_deity);

}  // namespace his_gen

#endif // ENTITY_DEITY_H
