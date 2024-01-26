project(unittests
   VERSION 0.0.1
   LANGUAGES CXX
   DESCRIPTION "Unit tests for the consolants project"
   )

include(CTest)

add_subdirectory(external)
add_subdirectory(consolants)
