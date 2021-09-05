cmake_minimum_required(VERSION 3.0)

project(event_sourcing VERSION 1.1.0 LANGUAGES CXX)

include_directories(include)
include_directories(src)

add_subdirectory(3rd_party/googletest)
add_subdirectory(3rd_party/json)
add_subdirectory(3rd_party/json-schema-validator)
add_subdirectory(src)
add_subdirectory(test)