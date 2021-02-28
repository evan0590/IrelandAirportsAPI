cmake_minimum_required(VERSION 3.2)
project(ireland-airport-api)
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(opt)

add_executable(query_api query_api.cpp)
target_link_libraries(query_api ${CPR_LIBRARIES})
include_directories(${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS})