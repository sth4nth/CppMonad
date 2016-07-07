cmake_minimum_required (VERSION 2.6)
project(monad)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(runTests test/test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_executable(monad src/main.cpp)
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fconcepts -pthread")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++1z -pthread")
