cmake_minimum_required(VERSION 3.5)

set(project_name history_generator)
project(${project_name})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Generator for the history of everything")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


######################################
# Locations of files for this project
file(GLOB_RECURSE glob_headers src/[a-z]*.h)
file(GLOB_RECURSE glob_sources src/[a-z]*.cpp)

set(sources ${sources} ${glob_sources})
set(headers ${headers} ${glob_headers})

######################################
# Define the binary we're building
add_executable(${project_name} ${sources} ${headers})

######################################
# Include directories

# Headers from our application
set(include_dirs ${CMAKE_CURRENT_SOURCE_DIR}/src ${include_dirs})

# Include Boost
set(include_dirs ${include_dirs} ${Boost_INCLUDE_DIRS})

target_include_directories(${project_name} PRIVATE ${include_dirs})
