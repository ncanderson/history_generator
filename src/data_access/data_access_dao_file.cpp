/**
 * Copyright (C) 2024 Nate Anderson - All Rights Reserved
 */

// Standard libs
#include <string>
#include <fstream>

// JSON
#include <deps/json.hpp>
#include <utils/json_describer.h>

// Application files
#include <utils/history_generator_utils.h>
#include <data_access/data_access_dao_file.h>
#include <models/data_definitions.h>

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_dao_file::Data_access_dao_file(const DAL_file_params& params)
  :
  Data_access_dao_base()
{ }

///////////////////////////////////////////////////////////////////////

his_gen::Data_access_dao_file::~Data_access_dao_file()
{
  // NOOP
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_file::Write_history(his_gen::Generated_history& generated_history)
{
  his_gen::Print_to_cout("Writing generated history to file");

  nlohmann::json output_json;
  try
  {
    output_json = generated_history;
  }
  catch(const nlohmann::json::exception& e)
  {
    his_gen::Print_to_cout("Error parsing generated_history to JSON");
    his_gen::Print_to_cout(e.what());
  }
  std::ofstream output_file;

  // Get text descriptions of all entities
  std::string all_descriptions = describe_entities(output_json);

  // Write main JSON
  output_file.open("/home/nanderson/nate_personal/projects/history_generator/output/sample_output.json");
  output_file << std::setw(2) << output_json;
  output_file.close();

  // Write entity descriptions out to a separate file
  std::ofstream output_file_text("/home/nanderson/nate_personal/projects/history_generator/output/entity_descriptions.txt");
  output_file_text << all_descriptions;
  output_file_text.close();
}

///////////////////////////////////////////////////////////////////////

void his_gen::Data_access_dao_file::Load_data_definitions()
{
  // Build composite structures
  his_gen::Data_definitions::Initialize();
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

std::string his_gen::Data_access_dao_file::describe_entities(nlohmann::json& output_json)
{
  std::string descriptions;

  if (!output_json.contains("entities") || !output_json["entities"].is_array())
  {
    return "No entities found.\n";
  }

  for (auto &entity : output_json["entities"])
  {
    std::string description = Json_describer::Describe_physicality(entity, false);

    // Collect all descriptions
    descriptions += description;
  }

  return descriptions;
}

///////////////////////////////////////////////////////////////////////
