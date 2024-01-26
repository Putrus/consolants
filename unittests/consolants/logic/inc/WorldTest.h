#pragma once
#include "../../../../consolants/logic/inc/World.h"

#include <gtest/gtest.h>

namespace ants::logic::ut
{
   class WorldTest : public testing::Test
   {
   protected:
      void SetUp() override;

      void TearDown() override;

      World world = World(100, 50, 0, 0);
   };
}