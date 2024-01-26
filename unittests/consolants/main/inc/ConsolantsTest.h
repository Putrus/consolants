#pragma once
#include "../../../../consolants/main/inc/Consolants.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace ants::main::ut
{
   class MockWindow : public view::Window
   {
   public:
      MockWindow();
      MOCK_METHOD(void, clear, (), (override));
      MOCK_METHOD(void, display, (), (const, override));
   };

   class MockConsolants : public Consolants
   {
   public:
      MockConsolants(std::shared_ptr<view::Window> window);
      void display();
      MOCK_METHOD(void, showAnthillsStatistics, (), (const, override));
      MOCK_METHOD(void, drawFoods, (), (override));
      MOCK_METHOD(void, drawAnthills, (), (override));
      MOCK_METHOD(void, drawAnts, (), (override));
   };
}