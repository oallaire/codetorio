cmake_minimum_required(VERSION 3.28)

project(codetorio)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add dependencies
include(cmake/CPM.cmake)
CPMAddPackage("gh:Neargye/magic_enum@0.9.7")
CPMAddPackage("gh:gabime/spdlog@1.15.2")

add_subdirectory(engine)
add_subdirectory(examples)
