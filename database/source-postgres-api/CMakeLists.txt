cmake_minimum_required(VERSION 3.2)
project(ireland-airport-api)
set (CMAKE_CXX_STANDARD 17)

find_package(PostgreSQL REQUIRED)

add_subdirectory(opt)

add_executable(create_table create_table.cpp)
add_executable(populate_departures_table populate_departures_table.cpp)
add_executable(populate_arrivals_table populate_arrivals_table.cpp)
add_executable(query_api query_api.cpp)

target_link_libraries(create_table pq)
target_link_libraries(populate_departures_table pq)
target_link_libraries(populate_arrivals_table pq)
target_link_libraries(query_api ${CPR_LIBRARIES})

include_directories(${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS} /usr/include/postgresql/)