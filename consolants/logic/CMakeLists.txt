project(consolants_logic)

set(HEADERS
   inc/Simulation.h
   )
set(SOURCES
   src/Simulation.cpp
   )

add_library(consolants_logic STATIC ${HEADERS} ${SOURCES})