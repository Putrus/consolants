#include "../inc/WorldTest.h"

#include "../../../../consolants/logic/inc/Anthill.h"

namespace ants::logic::ut
{
   void WorldTest::SetUp()
   {
      World world = World(100, 50, 0, 0);
   }

   void WorldTest::TearDown() {}

   TEST_F(WorldTest, AddFood)
   {
      world.addFood(10, 10);
      ASSERT_EQ(1, world.getFoods().size());
   }

   TEST_F(WorldTest, AddAnt)
   {
      Anthill anthill(0, 10, 10, world);
      world.addAnt(anthill, 15, 15);
      ASSERT_EQ(1, world.getAnts().size());
   }

   TEST_F(WorldTest, AddAnthill)
   {
      world.addAnthill(0, 20, 20);
      ASSERT_EQ(1, world.getAnthills().size());
   }

   TEST_F(WorldTest, RemoveAllAnts)
   {
      Anthill anthill(0, 10, 10, world);
      world.addAnt(anthill, 15, 15);
      world.addAnt(anthill, 15, 15);
      world.addAnt(anthill, 15, 15);
      world.removeAllAnts();
      ASSERT_TRUE(world.getAnts().empty());
   }
}