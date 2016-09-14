cmake_minimum_required(VERSION 3.6)
project(boost_tutorial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(any)
add_subdirectory(function)
add_subdirectory(make_shared)
add_subdirectory(proterty_tree)
add_subdirectory(smart_pointer)
add_subdirectory(thread)