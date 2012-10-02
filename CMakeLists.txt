cmake_minimum_required (VERSION 2.6)

project (lp)

set(
  SOURCES
  src/main.cpp
  src/problem.cpp
  )

include_directories(${CMAKE_SOURCE_DIR}/include/)
link_directories(${CMAKE_SOURCE_DIR}/lib/)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-W -Wall -std=c++11")

add_executable(
  lp
  ${SOURCES}
  )

target_link_libraries(
  lp
  glpk
  )
