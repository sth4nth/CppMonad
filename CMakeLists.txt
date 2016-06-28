cmake_minimum_required (VERSION 2.6)
project(monad)
add_executable(monad src/main.cpp)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fconcepts -pthread")
