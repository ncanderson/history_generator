cmake_minimum_required(VERSION 3.5)

project(history_generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

######################################
# Locations of files for this project
file(GLOB_RECURSE glob_headers src/[a-z]*.h)
file(GLOB_RECURSE glob_sources src/[a-z]*.cpp)

set(sources ${sources} ${glob_sources})
set(headers ${headers} ${glob_headers})

add_executable(history_generator main.cpp)
