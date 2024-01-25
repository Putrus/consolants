if(BUILD_TESTING)
   set(HEADERS)
   set(SOURCES
      src/PointTest.cpp
      )
   
   add_executable(consolants_math_ut ${HEADERS} ${SOURCES})

   target_link_libraries(consolants_math_ut PRIVATE GTest::gtest_main consolants_math)
   
   include(GoogleTest)
   gtest_discover_tests(consolants_math_ut)
endif()