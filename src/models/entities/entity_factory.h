/**
 * Copyright (C) 2025 Nate Anderson - All Rights Reserved
 */

#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

// Standard libs
#include <memory>

// JSON

// Application files
#include <defs/history_generator_defs.h>
#include <models/entities/entity_base.h>

namespace his_gen
{
/**
 * @brief Factory for creating entities from entity type enumerations
 * @details This class provides methods for creating new entities from types. It
 * cannot be instantiated.
 */
class Entity_factory
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Deleted constructor to make this class non-instantiable
   */
  Entity_factory() = delete;

  /**
   * @brief Deleted destructor to make this class non-instantiable
   */
  ~Entity_factory() = delete;

  /**
   * @brief Create an entity from its associated enumeration
   * @param entity_type The enumerated entity type
   * @param current_tick The current generation tick
   * @return A pointer to Entity_base, holding the instantiated derived entity type
   */
  static std::shared_ptr<his_gen::Entity_base> Create_entity(const his_gen::EEntity_type entity_type,
                                                             const uint64_t current_tick);

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class Entity_factory
}  // namespace his_gen

#endif // ENTITY_FACTORY_H
