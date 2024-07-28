#ifndef HISTORY_GENERATOR_MANAGER_H
#define HISTORY_GENERATOR_MANAGER_H

namespace his_gen
{
/**
 * @brief Backend manager for gss_ec_coverage application
 */
class History_generator_manager
{
public:
  // Attributes

  // Implementation
  /**
   * @brief Constructor.
   */
  History_generator_manager();

  /**
   * @brief Destructor.
   */
  virtual ~History_generator_manager(){}

  /**
   * @brief Run the application state machine
   */
  void Run();

protected:
  // Attributes

  // Implementation

private:
  // Attributes

  // Implementation

}; // class History_generator_manager
}  // namespace his_gen

#endif // HISTORY_GENERATOR_MANAGER_H
