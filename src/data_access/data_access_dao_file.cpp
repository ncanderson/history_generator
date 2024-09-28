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

void his_gen::Data_access_dao_file::Write_history(his_gen::Generated_history& generated_history)
{
  his_gen::Print_to_cout("Writing generated history to file");

  nlohmann::json output_json = generated_history;
  std::ofstream output_file;

  output_file.open("/home/nanderson/nate_personal/projects/history_generator/output/sample_output.json");
  output_file << std::setw(2) << output_json;
  output_file.close();
}

///////////////////////////////////////////////////////////////////////

his_gen::Data_definitions his_gen::Data_access_dao_file::Load_data_definitions()
{
  std::ifstream data_definitions_file("/home/nanderson/nate_personal/projects/history_generator/data/data_definitions.json");
  nlohmann::json data = nlohmann::json::parse(data_definitions_file);

  auto defs = data.template get<his_gen::Data_definitions>();
  return his_gen::Data_definitions(defs);
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_file::Load_all_names(std::vector<std::string>& names,
                                                   std::vector<std::string>& titles)
{
  std::ifstream names_file("/home/nanderson/nate_personal/projects/history_generator/data/names_and_titles.json");
  nlohmann::json file_data = nlohmann::json::parse(names_file);

  names = file_data.at("names");
  titles = file_data.at("titles");
}

///////////////////////////////////////////////////////////////////////
// END OF FILE
