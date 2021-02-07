cmake_minimum_required(VERSION 3.2)
project(ireland-airport-api)
set (CMAKE_CXX_STANDARD 11)

# Locate the aws sdk for c++ package.
find_package(AWSSDK REQUIRED COMPONENTS ec2)
find_package(AWSSDK REQUIRED COMPONENTS rds)

set(EXAMPLES "")
list(APPEND EXAMPLES "create_instance")
list(APPEND EXAMPLES "create_database")

# The executables to build.
foreach(EXAMPLE IN LISTS EXAMPLES)
    add_executable(${EXAMPLE} ${EXAMPLE}.cpp)
    target_link_libraries(${EXAMPLE} ${AWSSDK_LINK_LIBRARIES})
endforeach()
