/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs
#include <string>
#include <fstream>

// Application files
#include <utils/history_generator_utils.h>
#include <data_access/data_access_dao_file.h>

// JSON
#include <deps/json.hpp>

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_dao_file::Data_access_dao_file(const DAL_file_params& params)
    :
    Data_access_dao_base()
{

}

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_dao_file::~Data_access_dao_file()
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_file::Write_history(std::shared_ptr<his_gen::Generated_history> generated_history)
{
  his_gen::Print_to_cout("Writing generated history to file");

  nlohmann::json output_json = *generated_history;
  std::ofstream output_file;

  output_file.open("/home/nanderson/nate_personal/projects/history_generator/output/sample_output.json");
  output_file << std::setw(2) << output_json;
  output_file.close();
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_file::Load_data_definitions(std::shared_ptr<his_gen::Data_definitions> data_definitions)
{
  his_gen::Print_to_cout("file dao defs load function");

  std::ifstream data_definitions_file("/home/nanderson/nate_personal/projects/history_generator/data/data_definitions.json");
  nlohmann::json data = nlohmann::json::parse(data_definitions_file);

  /**
   * see here: https://stackoverflow.com/a/10826907/5543374
   * and here: https://stackoverflow.com/q/3310737/5543374
   * for something we're just observing, pass by const reference
   * if we need the value(s), pass by value.
   *
   * Consider pushing the creation of the shared data objects down into lower
   * classes, rather than up top in main()
   *
   * Basically the only reasonable parameters types are:
   * - shared_ptr<T> - Modify and take ownership
   * - shared_ptr<const T> - Don't modify, take ownership
   * - T& - Modify, no ownership
   * - const T& - Don't modify, no ownership
   * - T - Don't modify, no ownership, Cheap to copy
   *
   * So really, I think we want to have the manager class own the objects, since
   * it sits above the generators.
   */
  auto defs = data.template get<his_gen::Data_definitions>();
  data_definitions = std::make_shared<his_gen::Data_definitions>(defs);
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
