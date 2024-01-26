#include "../inc/AntTest.h"

namespace ants::logic::ut
{
   TEST_P(AntUpdateDestinationTest, AnthillDestination)
   {
      World world = World(100, 50, 1, 0);
      Ant ant = Ant(10, 10, *world.getAnthills()[0], world);
      for(const auto& foodPosition : GetParam())
      {
         world.addFood(foodPosition.x, foodPosition.y);
      }
      ant.update(0.050f);
      ASSERT_EQ(world.getAnthills()[0]->getPosition(), ant.getDestination());
   }

   INSTANTIATE_TEST_SUITE_P(FoodsAnthillDestination, AntUpdateDestinationTest,
      testing::Values(
         std::vector<math::Point>(),
         std::vector<math::Point>{ math::Point(30, 30) },
         std::vector<math::Point>{ math::Point(30, 30), math::Point(15, 15) },
         std::vector<math::Point>{ math::Point(30, 30), math::Point(15, 15), math::Point(45, 45) },
         std::vector<math::Point>{ math::Point(30, 30), math::Point(15, 15), math::Point(45, 45), math::Point(33, 33) }));
}