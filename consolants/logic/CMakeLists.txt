project(consolants_logic)

set(HEADERS
   inc/Ant.h
   inc/Anthill.h
   inc/Food.h
   inc/Object.h
   inc/Simulation.h
   inc/World.h
   )
set(SOURCES
   src/Ant.cpp
   src/Anthill.cpp
   src/Food.cpp
   src/Object.cpp
   src/Simulation.cpp
   src/World.cpp
   )

add_library(consolants_logic STATIC ${HEADERS} ${SOURCES})