cmake_minimum_required(VERSION 3.5)

set(project_name history_generator)
project(${project_name})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Generator for the history of everything")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

######################################
# Locations of files for this project

# src
file(GLOB_RECURSE glob_headers src/[a-z]*.h)
file(GLOB_RECURSE glob_sources src/[a-z]*.cpp)

# deps
file(GLOB_RECURSE glob_deps deps/[a-z]*.hpp)

# set 'em
set(sources ${sources} ${glob_sources})
set(headers ${headers} ${glob_headers} ${glob_deps})

######################################
# Define the binary we're building
add_executable(${project_name} ${sources} ${headers})

######################################
# Include directories

# Headers from our application
set(include_dirs ${CMAKE_CURRENT_SOURCE_DIR}/src ${include_dirs})

# Include Boost
find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${project_name} ${Boost_LIBRARIES})

target_include_directories(${project_name} PRIVATE ${include_dirs})
