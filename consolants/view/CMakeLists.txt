project(consolants_view)

set(HEADERS
   inc/Color.h
   inc/Color.h
   inc/Pixel.h
   inc/Window.h
   )
set(SOURCES
   src/Color.cpp
   src/Pixel.cpp
   src/Window.cpp
   )

add_library(consolants_view STATIC ${HEADERS} ${SOURCES})

target_link_libraries(consolants_view PRIVATE consolants_math)