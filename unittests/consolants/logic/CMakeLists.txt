if(BUILD_TESTING)
   set(HEADERS
      inc/AntTest.h
      inc/WorldTest.h
      )
   set(SOURCES
      src/AntTest.cpp
      src/FoodTest.cpp
      src/WorldTest.cpp
      )
   
   add_executable(consolants_logic_ut ${HEADERS} ${SOURCES})

   target_link_libraries(consolants_logic_ut PRIVATE GTest::gtest_main consolants_logic consolants_math)
   
   include(GoogleTest)
   gtest_discover_tests(consolants_logic_ut)
endif()