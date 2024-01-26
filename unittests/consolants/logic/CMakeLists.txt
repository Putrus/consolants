if(BUILD_TESTING)
   set(HEADERS)
   set(SOURCES
      src/FoodTest.cpp
      )
   
   add_executable(consolants_logic_ut ${HEADERS} ${SOURCES})

   target_link_libraries(consolants_logic_ut PRIVATE GTest::gtest_main consolants_logic consolants_math)
   
   include(GoogleTest)
   gtest_discover_tests(consolants_logic_ut)
endif()