project(consolants_math)

set(HEADERS
   inc/Point.h
   )
set(SOURCES
   src/Point.cpp
   )

add_library(consolants_math STATIC ${HEADERS} ${SOURCES})