cmake_minimum_required(VERSION 3.5)

set(project_name history_generator)
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
