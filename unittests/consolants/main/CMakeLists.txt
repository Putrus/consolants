if(BUILD_TESTING)
   set(HEADERS)
   set(SOURCES
      src/ConsolantsTest.cpp
      )
   
   add_executable(consolants_main_ut ${HEADERS} ${SOURCES})

   target_link_libraries(consolants_main_ut PRIVATE GTest::gtest_main)
   
   include(GoogleTest)
   gtest_discover_tests(consolants_main_ut)
endif()