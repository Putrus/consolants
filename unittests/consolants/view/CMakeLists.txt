if(BUILD_TESTING)
   set(HEADERS
      inc/ColorTest.h
      inc/CoutStringPreparatorTest.h
      inc/WindowTest.h
      )
   set(SOURCES
      src/ColorTest.cpp
      src/CoutStringPreparatorTest.cpp
      src/WindowTest.cpp
      src/PixelTest.cpp
      )
   
   add_executable(consolants_view_ut ${HEADERS} ${SOURCES})

   target_link_libraries(consolants_view_ut PRIVATE GTest::gtest_main consolants_view)
   
   include(GoogleTest)
   gtest_discover_tests(consolants_view_ut)
endif()