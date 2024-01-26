#include "../inc/AntTest.h"

namespace ants::logic::ut
{

   void AntTest::SetUp()
   {
   }

   void AntTest::TearDown()
   {
      world.removeAllAnts();
   }

   void AntTest::NewFoodDestinationTest(const std::vector<math::Point>& foodPositions)
   {
      for (const auto& foodPosition : foodPositions)
      {
         world.addFood(foodPosition.x, foodPosition.y);
      }

      ant.update(0.016f);
      bool testOk = false;
      for(const auto& foodPosition : foodPositions)
      {
         if (foodPosition == ant.getDestination())
         {
            testOk = true;
            break;
         }
      }
      ASSERT_TRUE(testOk);
   }

   TEST_F(AntTest, OneFoodDestination)
   {
      std::vector<math::Point> foodPositions = { math::Point(20, 20) };
      NewFoodDestinationTest(foodPositions);
   }
}