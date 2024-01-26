#pragma once
#include "../../../../consolants/logic/inc/Ant.h"
#include "../../../../consolants/logic/inc/Anthill.h"

#include <gtest/gtest.h>

namespace ants::logic::ut
{
   class AntUpdateDestinationTest : public testing::TestWithParam<std::vector<math::Point>>
   {
   };
}