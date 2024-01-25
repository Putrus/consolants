project(consolants_main)

set(HEADERS
   inc/Consolants.h
   )
set(SOURCES
   src/Consolants.cpp
   src/main.cpp
   )

add_executable(consolants ${HEADERS} ${SOURCES})

target_link_libraries(consolants PRIVATE consolants_logic consolants_view)
   