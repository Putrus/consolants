#pragma once
#include "../../../../consolants/logic/inc/Ant.h"
#include "../../../../consolants/logic/inc/Anthill.h"

#include <gtest/gtest.h>

namespace ants::logic::ut
{
   class AntTest : public testing::Test
   {
   protected:
      void SetUp() override;

      void TearDown() override;

      void NewFoodDestinationTest(const std::vector<math::Point>& foodPositions);

      World world = World(100, 50, 1, 0);
      Ant ant = Ant(10, 10, *world.getAnthills()[0], world);
   };
}